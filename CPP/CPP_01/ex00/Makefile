# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 16:55:39 by lrondia           #+#    #+#              #
#    Updated: 2022/11/26 16:59:22 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp\
		Zombie.cpp\
		NewZombie.cpp\
		RandomChump.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = BraiiiiiiinnnzzzZ

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
