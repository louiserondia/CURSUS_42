# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 16:55:39 by lrondia           #+#    #+#              #
#    Updated: 2022/11/28 19:19:38 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp \

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Sed_is_for_losers

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm *.replace

re:	fclean all

test: all
	./$(NAME) file1 louise lol
	@cat file1 ; echo "\n"
	@cat file1.replace ; echo "\n"
	./$(NAME) file2 i O
	@cat file2 ; echo "\n"
	@cat file2.replace ; echo "\n"

.PHONY: all clean fclean re
