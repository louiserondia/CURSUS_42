# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 12:03:25 by lrondia           #+#    #+#              #
#    Updated: 2022/01/22 12:43:05 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c\
		sort_char.c\
		utils.c\
		conversion.c\
		check_simple_flags.c\
		return_len.c\
		check_precision.c\
		debug.c\

LIB = ./LIBFT

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		make -C $(LIB)
		ar rcs ${NAME} ${OBJS} ./LIBFT/*.o

all:	$(NAME)

clean:
	${RM} ${OBJS}
	make clean -C $(LIB)

fclean:	
	${RM} ${OBJS}
	${RM} ${NAME}
	make fclean -C $(LIB)

re: fclean all add

.PHONY: all clean fclean re add LIBFT
