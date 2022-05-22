/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/22 20:10:39 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_and_sleep(t_philo *philo)
{
	while (philo->table->someone_died == 0 && philo->table->are_full == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		sem_wait(philo->table->sem_fork);
		sem_for_prints(philo, "has taken a fork\n");
		sem_wait(philo->table->sem_fork);
		sem_for_prints(philo, "has taken a fork\n");
		philo->last_meal = time_now();
		sem_for_prints(philo, "is eating\n");
		philo->nb_meals++;
		ft_sleep(philo->table, philo->table->time_to_eat);
		sem_post(philo->table->sem_fork);
		sem_post(philo->table->sem_fork);
		sem_for_prints(philo, "is sleeping\n");
		ft_sleep(philo->table, philo->table->time_to_sleep);
		sem_for_prints(philo, "is thinking\n");
	}
	exit (1);
}

void	child(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(philo->table, 50);
	// pthread_create(&philo->table->dead, NULL, (void *)is_dead, philo->table);
	// pthread_create(&philo->table->full, NULL, 
	// 	(void *)are_their_belly_full, philo->table);
	eat_and_sleep(philo);
	// if (pthread_join(philo->table->dead, NULL) != 0)
	// 	return (0);
	// if (pthread_join(philo->table->full, NULL) != 0)
	// 	return (0);
}

void	fork_and_wait(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			exit (0);
		else if (table->pid[i] == 0)
			child(&table->philo[i]);
		i++;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		waitpid(table->pid[i], NULL, 0);
		i++;
	}
}
