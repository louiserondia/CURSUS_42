# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 16:40:12 by lrondia           #+#    #+#              #
#    Updated: 2022/05/23 18:45:23 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	philo/main.c\
		philo/utils.c\
		philo/utils_philo.c\
		philo/initialization.c\
		philo/thread_mutex.c\
		philo/action.c\

BONUS_SRCS = 	philo_bonus/main.c\
				philo_bonus/initialization.c\
				philo_bonus/utils.c\
				philo_bonus/utils_philo.c\
				philo_bonus/child.c\
				philo_bonus/mom.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread

NAME = philo/philo
BONUS_NAME = philo_bonus/philo_bonus

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	
$(BONUS_NAME):	$(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

all: $(NAME)
bonus: $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	
fclean:	clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
