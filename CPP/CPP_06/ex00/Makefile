# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 16:55:39 by lrondia           #+#    #+#              #
#    Updated: 2022/12/29 15:10:31 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert

all : $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
