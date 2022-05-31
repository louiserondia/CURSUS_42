/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/31 13:02:44 by lrondia          ###   ########.fr       */
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
# include <unistd.h>
# include <stdatomic.h>
# include <stdbool.h>

struct	s_table;

typedef struct s_philo
{
	int				id;
	int				state;
	atomic_long		last_meal;
	atomic_int		nb_meals;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	pthread_t		*tid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*prints;
	pthread_mutex_t	*death;
	atomic_int		nb_philo;
	atomic_int		total_meals;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
	atomic_bool		are_full;
	atomic_bool		someone_died;
}	t_table;

// utils

int		print_error(char *str);
int		ft_strlen(char *str);
int		is_digit(char *str);
int		ft_atoi_restrict(char *str);
void	ft_sleep(t_table *table, int time);
long	time_now(void);
void	is_dead(t_table *table);
void	are_their_belly_full(t_table *table);
void	mutex_for_prints(t_philo *philo, pthread_mutex_t *mutex, char *str);

// algo

int		parsing(int argc, char **argv);
int		initialization(t_table *table, int argc, char **argv);
int		ft_create_threads(t_table *table);
int		ft_create_mutexes(t_table *table);
int		ft_destroy(t_table *table);
int		thread(t_philo *philo);

#endif
