# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 16:15:14 by lrondia           #+#    #+#              #
#    Updated: 2022/11/26 16:20:55 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Account.cpp\
		tests.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = account

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re