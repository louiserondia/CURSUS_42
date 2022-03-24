# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:22:56 by lrondia           #+#    #+#              #
#    Updated: 2022/03/24 16:21:29 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	mandatory/main.c\
		mandatory/actions.c\
		mandatory/utils.c\
		mandatory/read_map.c\
		mandatory/init_sprites.c\
		mandatory/set_sprites.c\
		mandatory/errors.c\
		mandatory/error_wall.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

BONUS_SRCS = bonus/main.c\
			bonus/actions.c\
			bonus/utils.c\
			bonus/read_map.c\
			bonus/init_sprites.c\
			bonus/set_sprites.c\
			bonus/errors.c\
			bonus/error_wall.c\
			bonus/factory_me.c\
			bonus/factory_monster.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = /usr/local/lib/
FRAMEWORK = -framework OpenGL -framework AppKit
PRINTF = ./ft_printf

NAME = so_long
BONUS_NAME = so_long_bonus

all: printf $(NAME)

printf:
	make -C $(PRINTF)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX) -lmlx $(FRAMEWORK) ft_printf/libftprintf.a

$(BONUS_NAME):	$(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L $(MLX) -lmlx $(FRAMEWORK) ft_printf/libftprintf.a

bonus: printf $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make clean -C $(PRINTF)

fclean:	clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
