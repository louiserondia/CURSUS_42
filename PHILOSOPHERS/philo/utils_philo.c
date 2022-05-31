/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:58:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/31 13:09:56 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	long			res;
	struct timeval	time;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}

void	mutex_for_prints(t_philo *philo, pthread_mutex_t *mutex, char *str)
{
	int		phi;
	long	now;

	phi = philo->id + 1;
	now = time_now() - philo->table->start_time;
	pthread_mutex_lock(mutex);
	if (philo->table->someone_died == 0 && philo->table->are_full == 0)
		printf("%ld %d %s", now, phi, str);
	pthread_mutex_unlock(mutex);
}

void	is_dead(t_table *table)
{
	int		i;
	long	now;

	while (table->someone_died == 0 && table->are_full == 0)
	{
		usleep(100);
		i = 0;
		while (i < table->nb_philo)
		{
			now = time_now();
			if (now >= table->philo[i].last_meal + table->time_to_die)
			{
				pthread_mutex_lock(table->death);
				pthread_mutex_lock(table->prints);
				table->someone_died = 1;
				printf("%ld %d %s", now - table->start_time, i + 1, "died\n");
				pthread_mutex_unlock(table->prints);
				pthread_mutex_unlock(table->death);
				break ;
			}
			i++;
		}
		if (table->total_meals != -1)
			are_their_belly_full(table);
	}
}

void	are_their_belly_full(t_table *table)
{
	int	i;

	i = 0;
	if (table->total_meals == 0)
		table->are_full = 1;
	while (i < table->nb_philo)
	{
		if (table->philo[i].nb_meals < table->total_meals)
			break ;
		i++;
	}
	if (i == table->nb_philo)
		table->are_full = 1;
}

void	ft_sleep(t_table *table, int time)
{
	long	now;
	long	start;

	start = time_now();
	while (table->someone_died == 0)
	{
		now = time_now();
		if (now - start >= time)
			break ;
		usleep(100);
	}
}
