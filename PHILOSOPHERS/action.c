/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/03 17:36:05 by lrondia          ###   ########.fr       */
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

void	eat_and_sleep(t_philo *philo, int next)
{
	int	phi;
	time_t	now;

	phi = philo->id;
	now = time_now();
	philo->last_meal = now;
	philo->table->fork[phi] = 1;
	philo->table->fork[next] = 1;
	printf("%ld %d is eating\n", now, phi);
	usleep(philo->table->time_to_eat * 1000);
	philo->table->fork[phi] = 0;
	philo->table->fork[next] = 0;
	printf("%ld %d is sleeping\n", now, phi);
	usleep(philo->table->time_to_sleep * 1000);
}

void	can_they_eat(t_philo *philo)
{
	int	phi;
	int	next;

	phi = philo->id;
	next = philo->table->nb_philo - 1;
	if (phi % 2 == 0 && philo->table->nb_meals % 2 == 0 && phi != next)
		eat_and_sleep(philo, phi + 1);
	else if (phi % 2 == 1 && philo->table->nb_meals % 2 == 1 && phi != next)
		eat_and_sleep(philo, phi + 1);
	else if (phi == next && philo->table->fork[0] == 0
		&& philo->table->fork[phi] == 0)
		eat_and_sleep(philo, 0);
}

int	action(t_philo *philo)
{
	(void) philo;

	printf("%p\n", &philo->table->mid);
	// pthread_mutex_lock(&philo->table->mid);
	// if (philo->table->someone_died == 1)
	// 	return (0);
	can_they_eat(philo);
	// pthread_mutex_unlock(&philo->table->mid);
	return (1);
}
