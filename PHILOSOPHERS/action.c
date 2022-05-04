/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/04 18:55:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_sleep(t_philo *philo)
{
	int	phi;
	int	next;

	phi = philo->id;
	next = phi + 1;
	if (phi == philo->table->nb_philo)
		next = 0;
	while (philo->table->someone_died == 0)
	{
		pthread_mutex_lock(&philo->table->fork[phi]);
		pthread_mutex_lock(&philo->table->fork[next]);
		mutex_for_prints(philo, philo->table->prints[0], "is eating");
		usleep(philo->table->time_to_eat * 1000);
		philo->last_meal = time_now();
		pthread_mutex_unlock(&philo->table->fork[phi]);
		pthread_mutex_unlock(&philo->table->fork[next]);
		mutex_for_prints(philo, philo->table->prints[1], "is sleeping");
		usleep(philo->table->time_to_sleep * 1000);
		mutex_for_prints(philo, philo->table->prints[2], "is thinking");
	}
	return ;
}

int	thread(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(15);
	eat_and_sleep(philo);
	return (1);
}
