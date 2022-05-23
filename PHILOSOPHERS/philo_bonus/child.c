/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/23 18:56:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_and_sleep(t_table *table)
{
	while (table->someone_died == 0 && table->are_full == 0)
	{
		if (table->nb_philo == 1)
			continue ;
		sem_wait(table->sem_fork);
		sem_for_prints(table, "has taken a fork\n");
		sem_wait(table->sem_fork);
		sem_for_prints(table, "has taken a fork\n");
		sem_for_prints(table, "is eating\n");
		table->last_meal = time_now();
		table->nb_meals++;
		ft_sleep(table, table->time_to_eat);
		sem_post(table->sem_fork);
		sem_post(table->sem_fork);
		sem_for_prints(table, "is sleeping\n");
		ft_sleep(table, table->time_to_sleep);
		sem_for_prints(table, "is thinking\n");
	}
	exit (1);
}

void	child(t_table *table, int id)
{
	if (table->id % 2 == 0)
		ft_sleep(table, 50);
	table->id = id;
	table->last_meal = time_now();
	pthread_create(&table->dead, NULL, (void *)is_dead, table);
	// pthread_create(&table->full, NULL, (void *)are_their_belly_full, table);
	eat_and_sleep(table);
	// if (pthread_join(table->dead, NULL) != 0)
	// 	exit (1);
	// if (pthread_join(table->full, NULL) != 0)
	// 	exit (1);
}
