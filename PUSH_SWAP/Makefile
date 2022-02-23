# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 14:21:13 by lrondia           #+#    #+#              #
#    Updated: 2022/02/22 19:56:17 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		parsing.c\
		utils.c\
		push_swap.c\

NAME = push_swap

OBJS = $(SRCS:.c=.o)

LIB = ./libft

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME)

libft:
	make -C $(LIB)
	make bonus -C $(LIB)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIB) -lft


clean:
	make clean -C $(LIB)
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
