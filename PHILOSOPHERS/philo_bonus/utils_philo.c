/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:58:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/30 18:03:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	time_now(void)
{
	long			res;
	struct timeval	time;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}

void	is_dead(t_table *table)
{
	int	i;

	while (1)
	{
		usleep(1000);
		i = 0;
		while (i < table->nb_philo)
		{
			if (table->total_meals != -1
				&& table->nb_meals == table->total_meals)
				exit (0);
			sem_wait(table->sem_dead);
			if (time_now() >= table->last_meal + table->time_to_die)
			{
				sem_wait(table->sem_print);
				printf("%ld %d %s", time_now() - table->start_time,
					table->id + 1, "died\n");
				exit (1);
				sem_post(table->sem_print);
			}
			sem_post(table->sem_dead);
			i++;
		}
	}
}

void	ft_sleep(int time)
{
	int	now;
	int	start;

	start = time_now();
	while (1)
	{
		now = time_now();
		if (now - start >= time)
			break ;
		usleep(100);
	}
}

void	sem_for_prints(t_table *table, char *str)
{
	int		phi;
	long	now;

	phi = table->id + 1;
	now = time_now() - table->start_time;
	sem_wait(table->sem_print);
	printf("%ld %d %s", now, phi, str);
	sem_post(table->sem_print);
}
