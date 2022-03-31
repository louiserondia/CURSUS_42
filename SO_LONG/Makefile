# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:22:56 by lrondia           #+#    #+#              #
#    Updated: 2022/03/31 18:19:35 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	mandatory/main.c\
		mandatory/read_map.c\
		mandatory/actions.c\
		mandatory/utils.c\
		mandatory/errors/errors.c\
		mandatory/errors/error_wall.c\
		mandatory/factory/init_sprites.c\
		mandatory/factory/set_sprites.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

BONUS_SRCS = bonus/main.c\
			bonus/read_map.c\
			bonus/actions.c\
			bonus/animation.c\
			bonus/utils.c\
			bonus/destroy.c\
			bonus/errors/errors.c\
			bonus/errors/error_wall.c\
			bonus/factory/init_sprites.c\
			bonus/factory/factory_me.c\
			bonus/factory/factory_gun.c\
			bonus/factory/factory_other.c\
			bonus/factory/factory_number.c\
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
