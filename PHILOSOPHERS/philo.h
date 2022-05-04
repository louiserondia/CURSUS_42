/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/04 18:56:16 by lrondia          ###   ########.fr       */
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

struct	s_table;

typedef struct s_philo
{
	int				id;
	int				state;
	int				nb_fork_in_hand;
	time_t			last_meal;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	pthread_t		*tid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	prints[3];
	int				nb_philo;
	int				nb_meals;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				someone_died;
}	t_table;

// utils

int		ft_strlen(char *str);
int		is_digit(char *str);
int		ft_atoi_restrict(char *str);
void	ft_printf_state(t_table *table);
time_t	time_now(void);

// algo

int		parsing(int argc, char **argv);
int		initialization(t_table *table, int argc, char **argv);
int		ft_create_threads(t_table *table);
int		ft_create_mutexes(t_table *table);
void	ft_lock_mutex(t_table *table);
void	ft_unlock_mutex(t_table *table);
int		ft_destroy(t_table *table);
int		thread(t_philo *philo);
int		is_dead(t_table *table);
void	mutex_for_prints(t_philo *philo, pthread_mutex_t mutex, char *str);

#endif
