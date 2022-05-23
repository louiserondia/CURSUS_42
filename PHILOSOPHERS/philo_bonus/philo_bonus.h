/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:22:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/23 18:57:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <signal.h>

typedef struct s_table
{
	int				id;
	atomic_long		last_meal;
	int				nb_meals;
	sem_t			*sem_fork;
	sem_t			*sem_dead;
	sem_t			*sem_print;
	pthread_t		dead;
	pthread_t		full;
	int				*pid;
	int				nb_philo;
	int				total_meals;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
	atomic_bool		are_full;
	atomic_bool		someone_died;
}	t_table;

void	initialization(t_table *table, int argc, char **argv);
void	fork_and_wait(t_table *table);
void	are_their_belly_full(t_table *table);
void	is_dead(t_table *table);
void	ft_destroy(t_table *table);
void	sem_for_prints(t_table *table, char *str);
void	child(t_table *table, int id);

//	UTILS

int		is_digit(char *str);
int		ft_atoi_restrict(char *str);
long	time_now(void);
void	ft_sleep(t_table *table, int time);

#endif
