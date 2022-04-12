# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 12:13:43 by lrondia           #+#    #+#              #
#    Updated: 2022/04/12 19:16:17 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		ft_split.c\
		utils.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF = ./ft_printf

NAME = pipex

all: $(NAME)


$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
