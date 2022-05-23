/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:58:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/23 18:57:42 by lrondia          ###   ########.fr       */
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
	int		i;
	long	now;

	while (table->someone_died == 0 && table->are_full == 0)
	{
		usleep(1000);
		i = 0;
		while (i < table->nb_philo)
		{
			now = time_now();
			sem_wait(table->sem_dead);
			if (now >= table->last_meal + table->time_to_die)
			{
				sem_for_prints(table, "is dead\n");
				table->someone_died = 1;
				exit (1);
			}
			sem_post(table->sem_dead);
			i++;
		}
	}
}

void	are_their_belly_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (table->nb_meals != table->total_meals)
			break ;
		i++;
	}
	if (i == table->nb_philo)
		table->are_full = true;
}

void	ft_sleep(t_table *table, int time)
{
	int	now;
	int	start;

	start = time_now();
	while (table->someone_died == 0)
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
	int		now;

	if (table->someone_died == 1)
		return ;
	phi = table->id + 1;
	now = time_now() - table->start_time;
	sem_wait(table->sem_print);
	printf("%d %d %s", now, phi, str);
	sem_post(table->sem_print);
}
