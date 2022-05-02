/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/02 16:50:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_table *table)
{
	int		i;
	time_t	now;

	while (1)
	{
		i = 0;
		now = time_now();
		while (i < table->nb_philo)
		{
			if (now > table->philo[i]->last_meal + table->time_to_die)
			{
				printf("%ld %d is dead\n", now, i);
				table->someone_died = 1;
				return (0);
			}
			i++;
		}
	}
	return (1);
}

void	eat_and_sleep(t_table *table, int next)
{
	int	phi;
	time_t	now;

	phi = table->current_philo;
	now = time_now();
	table->philo[phi]->last_meal = now;
	table->philo[phi]->left_fork = 1;
	table->philo[next]->left_fork = 1;
	printf("%ld %d is eating\n", now, phi);
	usleep(table->time_to_eat * 1000);
	table->philo[phi]->left_fork = 0;
	table->philo[next]->left_fork = 0;
	printf("%ld %d is sleeping\n", now, phi);
	usleep(table->time_to_sleep * 1000);
}

void	can_they_eat(t_table *table)
{
	int	phi;
	int	last;

	phi = table->current_philo;
	printf("current : %d\n", phi);
	last = table->nb_philo - 1;
	printf("last : %d\n", last);
	if (phi % 2 == 0 && table->nb_meals % 2 == 0 && phi != last)
		eat_and_sleep(table, phi + 1);
	else if (phi % 2 == 1 && table->nb_meals % 2 == 1 && phi != last)
		eat_and_sleep(table, phi + 1);
	else if (phi == last && table->philo[0]->left_fork == 0
		&& table->philo[phi - 1]->left_fork == 0)
		eat_and_sleep(table, 0);
}

int	action(t_table *table)
{
	ft_lock_mutex(table);
	if (table->someone_died == 1)
		return (0);
	can_they_eat(table);
	ft_unlock_mutex(table);
	return (1);
}
