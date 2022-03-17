# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 14:21:13 by lrondia           #+#    #+#              #
#    Updated: 2022/03/17 11:54:38 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			mandatory/main.c				mandatory/push.c\
				mandatory/utils.c				mandatory/swap.c\
				mandatory/parsing.c				mandatory/rotate.c\
				mandatory/utils_list.c			mandatory/sort_big.c\
				mandatory/sort_little.c			mandatory/make_actions.c\
				mandatory/utils_parsing.c		mandatory/reverse_rotate.c\

BONUS_SCRS =	bonus/checker.c\
				bonus/operations.c\
				bonus/get_next_line.c\
				mandatory/swap.c\
				mandatory/push.c\
				mandatory/utils.c\
				mandatory/rotate.c\
				mandatory/parsing.c\
				mandatory/utils_list.c\
				mandatory/utils_parsing.c\
				mandatory/reverse_rotate.c\
				
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

$(BONUS_NAME):	$(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L $(LIB) -lft

bonus:	libft $(BONUS_NAME)

clean:
	make clean -C $(LIB)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus
