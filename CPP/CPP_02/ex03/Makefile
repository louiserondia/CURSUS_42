# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 16:55:39 by lrondia           #+#    #+#              #
#    Updated: 2022/12/06 11:49:49 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	Fixed.cpp \
		Point.cpp \
		Bsp.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bsp

all : $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
