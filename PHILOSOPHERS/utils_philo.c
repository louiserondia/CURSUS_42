/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:58:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/20 16:53:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_now(void)
{
	int				res;
	struct timeval	time;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}

void	is_dead(t_table *table)
{
	int	i;
	int	now;

	while (table->someone_died == 0 && table->are_full == 0)
	{
		usleep(1000);
		i = 0;
		now = time_now();
		while (i < table->nb_philo)
		{
			if (now > table->philo[i].last_meal + table->time_to_die)
			{
				mutex_for_prints(&table->philo[i], table->prints, "is dead\n");
				table->someone_died = 1;
			}
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
		if (table->philo[i].nb_meals != table->total_meals)
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
		if (now - start > time)
			break ;
		usleep(100);
	}
}
