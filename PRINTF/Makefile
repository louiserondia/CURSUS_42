# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 12:03:25 by lrondia           #+#    #+#              #
#    Updated: 2022/01/26 20:09:44 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c\
		sort_char.c\
		init_flags.c\
		utils.c\
		len.c\
		conversion_char.c\
		conversion_int.c\
		check_simple_flags.c\
		return_padding.c\
		check_precision.c\
		check_zero.c\
		check_minus_char.c\
		check_minus_int.c\

LIB = ./libft

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		make -C $(LIB)
		cp $(LIB)/libft.a $(NAME)
		ar rcs ${NAME} ${OBJS}

bonus: all

all:	$(NAME)

clean:
	${RM} ${OBJS}
	make clean -C $(LIB)

fclean:	
	${RM} ${OBJS}
	${RM} ${NAME}
	make fclean -C $(LIB)

re: fclean all add

.PHONY: all clean fclean re add bonus libft
