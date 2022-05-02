/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/02 14:04:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int	state;						//0 = thinking	1 = eating	2 = sleeping
	int	left_fork;					//0 = free		1 = taken	-> left fork for each philo 
	int	nb_fork_in_hand;			//0, 1 or 2
}	t_philo;

typedef struct s_table
{
	t_philo			**philo;
	pthread_t		*tid;
	pthread_mutex_t	*mid;
	int				nb_philo;
	int				nb_meals;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
}	t_table;

// utils

int		ft_strlen(char *str);
int		is_digit(char *str);
int		ft_atoi_restrict(char *str);
void	ft_printf_state(t_table *table);

// algo

int		parsing(int argc, char **argv);
int		initialization(t_table *table, int argc, char **argv);
int		ft_create_threads(t_table *table);
int		ft_create_mutexes(t_table *table);
int		ft_destroy(t_table *table);
void	*action(t_table *table);

#endif
