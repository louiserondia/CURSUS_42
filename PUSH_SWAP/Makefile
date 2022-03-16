# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 14:21:13 by lrondia           #+#    #+#              #
#    Updated: 2022/03/16 21:24:06 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			pushswap/main.c					pushswap/push.c\
				pushswap/utils.c				pushswap/swap.c\
				pushswap/parsing.c				pushswap/rotate.c\
				pushswap/utils_list.c			pushswap/sort_big.c\
				pushswap/sort_little.c			pushswap/make_actions.c\
				pushswap/utils_parsing.c		pushswap/reverse_rotate.c\

BONUS_SCRS =	bonus/checker.c\
				bonus/operations.c\
				bonus/get_next_line.c\
				pushswap/swap.c\
				pushswap/push.c\
				pushswap/utils.c\
				pushswap/rotate.c\
				pushswap/parsing.c\
				pushswap/utils_list.c\
				pushswap/utils_parsing.c\
				pushswap/reverse_rotate.c\
				
NAME = push_swap
BONUS_NAME = checker

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SCRS:.c=.o)

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

bonus:	libft $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L $(LIB) -lft

clean:
	make clean -C $(LIB)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus
