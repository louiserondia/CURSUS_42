# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:22:56 by lrondia           #+#    #+#              #
#    Updated: 2022/03/23 12:22:10 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		actions.c\
		utils.c\
		read_map.c\
		init_sprites.c\
		set_sprites.c\
		errors.c\
		error_wall.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = /usr/local/lib/
FRAMEWORK = -framework OpenGL -framework AppKit
PRINTF = ./ft_printf

NAME = so_long


$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX) -lmlx $(FRAMEWORK) ft_printf/libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: printf $(NAME)

printf:
	make -C $(PRINTF)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
