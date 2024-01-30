import {
  Body,
  Controller,
  Patch,
  UseGuards,
  Post,
  UploadedFile,
  UseInterceptors,
  ParseFilePipe,
  FileTypeValidator,
  MaxFileSizeValidator,
  ForbiddenException,
  NotFoundException,
  Get,
  Param,
  StreamableFile,
} from '@nestjs/common';
import { GetUser } from '../auth/decorator';
import { JwtGuard } from '../auth/guard';
import { EditUserDto, FriendDto } from './dto';
import { UserService } from './user.service';
import { FileInterceptor } from '@nestjs/platform-express';
import { PrismaClient } from '@prisma/client';
import { createReadStream } from 'fs';
import { join } from 'path';
import * as fs from 'fs';

@UseGuards(JwtGuard)
@Controller('users')
export class UserController {
  constructor(private userService: UserService, private prisma: PrismaClient) {}

  @Get('me')
  getMe(@GetUser('id') userId: number) {
    const user = this.prisma.user.findUnique({ where: { id: userId } });
    return user;
  }

  @Get('avatar/me')
  getMyPhoto(@GetUser() user) {
    const path = join(process.cwd(), '/upload', `${user.login}.png`);
    if (!fs.existsSync(path)) {
      throw new NotFoundException('Avatar not found');
    }
    const file = createReadStream(
      join(process.cwd(), '/upload', `${user.login}.png`),
    );
    return new StreamableFile(file);
  }

  @Get('info/:id')
  getInfo(@Param('id') id: string) {
    const parseId = parseInt(id.toString());
    return this.prisma.user.findUnique({ where: { id: parseId } });
  }

  @Get('info/name/:username')
  getInfoByName(@Param('username') username: string) {
    return this.prisma.user.findUnique({ where: { username: username } });
  }

  @Get('avatar/:id')
  @UseInterceptors()
  async getUserPhoto(@Param('id') id: string) {
    const path = join(process.cwd(), '/upload', `${id}.png`);
    if (!fs.existsSync(path)) {
      throw new NotFoundException('Avatar not found');
    }
    const file = createReadStream(join(process.cwd(), '/upload', `${id}.png`));
    return new StreamableFile(file);
  }

  @UseGuards(JwtGuard)
  @Get('me/friends')
  async getUserFriends(@GetUser() user) {
    const friends = (await this.prisma.user.findMany({
      where: { id: { in: user.friends } },
    })) as any;
    friends.forEach((friend) => {
      friend.status = this.userService.getStatus(friend.id);
    });
    return friends;
  }

  @Patch('edit')
  async editUser(@GetUser('id') userId: number, @Body() dto: EditUserDto) {
    return this.userService.editUser(userId, dto);
  }

  @UseInterceptors(FileInterceptor('file'))
  @Post('upload')
  uploadFileAndPassValidation(
    @GetUser('id') id,
    @UploadedFile(
      new ParseFilePipe({
        validators: [
          new MaxFileSizeValidator({ maxSize: 10000000 }),
          new FileTypeValidator({ fileType: /(jpg|jpeg|png)$/ }),
        ],
      }),
    )
    file: Express.Multer.File,
  ) {
    return this.userService.saveImageFromBuffer(file, `${id}.png`);
  }

  @Patch('remove-friend')
  async removeFriend(@GetUser('id') id, @Body() dto: FriendDto) {
    if (id == dto.friendId)
      throw new ForbiddenException('You cannot remove yourself as a friend');
    const prisma_friend = await this.prisma.user.findUnique({
      where: { id: dto.friendId },
    });
    if (!prisma_friend) throw new NotFoundException('User not found');
    return await this.userService.removeFriend(id, prisma_friend.id);
  }

  @Get('me/blocks')
  getMyBlocks(@GetUser() user) {
    const blocks = this.userService.getUserBlocks(user.username);
    return blocks;
  }

  @UseGuards(JwtGuard)
  @Post('block')
  async blockUser(
    @Body('userId') userId: number,
    @Body('blockedId') blockedId: number,
  ) {
    const block = this.userService.blockUser(userId, blockedId);
    return block;
  }

  @UseGuards(JwtGuard)
  @Post('unblock')
  async unblockUser(
    @Body('userId') userId: number,
    @Body('blockedId') blockedId: number,
  ) {
    const block = this.userService.unblockUser(userId, blockedId);
    return block;
  }
}
