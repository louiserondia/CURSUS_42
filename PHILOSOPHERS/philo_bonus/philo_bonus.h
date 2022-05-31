/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:22:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/30 18:03:51 by lrondia          ###   ########.fr       */
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
	atomic_int		nb_meals;
	sem_t			*sem_fork;
	sem_t			*sem_dead;
	sem_t			*sem_print;
	pthread_t		dead;
	int				*pid;
	int				nb_philo;
	int				total_meals;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
}	t_table;

//	UTILS

int		error_exit(char *str);
int		is_digit(char *str);
int		ft_atoi_restrict(char *str);
long	time_now(void);
void	ft_sleep(int time);
void	is_dead(t_table *table);
void	sem_for_prints(t_table *table, char *str);

//  ALGO

void	initialization(t_table *table, int argc, char **argv);
void	fork_and_wait(t_table *table);
void	child(t_table *table, int id);
void	ft_destroy(t_table *table);

#endif
