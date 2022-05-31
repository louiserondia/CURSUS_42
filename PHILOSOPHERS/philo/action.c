/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/31 13:03:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_sleep(t_philo *philo, int phi, int next)
{
	while (philo->table->someone_died == 0 && philo->table->are_full == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		pthread_mutex_lock(&philo->table->fork[phi]);
		mutex_for_prints(philo, philo->table->prints, "has taken a fork\n");
		pthread_mutex_lock(&philo->table->fork[next]);
		mutex_for_prints(philo, philo->table->prints, "has taken a fork\n");
		mutex_for_prints(philo, philo->table->prints, "is eating\n");
		philo->last_meal = time_now();
		ft_sleep(philo->table, philo->table->time_to_eat);
		pthread_mutex_unlock(&philo->table->fork[phi]);
		pthread_mutex_unlock(&philo->table->fork[next]);
		philo->nb_meals++;
		mutex_for_prints(philo, philo->table->prints, "is sleeping\n");
		ft_sleep(philo->table, philo->table->time_to_sleep);
		mutex_for_prints(philo, philo->table->prints, "is thinking\n");
	}
	return ;
}

int	thread(t_philo *philo)
{
	int	phi;
	int	next;

	phi = philo->id;
	next = phi + 1;
	if (phi == philo->table->nb_philo - 1)
		next = 0;
	if (philo->id % 2 == 1)
		ft_sleep(philo->table, 50);
	if (philo->table->someone_died == 0)
		eat_and_sleep(philo, phi, next);
	return (1);
}
