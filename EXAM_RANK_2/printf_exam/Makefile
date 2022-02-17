# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 20:01:21 by lrondia           #+#    #+#              #
#    Updated: 2022/02/14 20:11:49 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c\

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean

re: fclean all add

.PHONY: all clean fclean re add
