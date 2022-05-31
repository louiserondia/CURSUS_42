/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/30 14:51:35 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_and_sleep(t_table *table)
{
	while (1)
	{
		sem_wait(table->sem_fork);
		sem_for_prints(table, "has taken a fork\n");
		sem_wait(table->sem_fork);
		sem_for_prints(table, "has taken a fork\n");
		sem_for_prints(table, "is eating\n");
		table->last_meal = time_now();
		ft_sleep(table->time_to_eat);
		sem_post(table->sem_fork);
		sem_post(table->sem_fork);
		table->nb_meals++;
		sem_for_prints(table, "is sleeping\n");
		ft_sleep(table->time_to_sleep);
		sem_for_prints(table, "is thinking\n");
	}
}

void	child(t_table *table, int id)
{
	if (table->id % 2 == 1)
		ft_sleep(50);
	table->id = id;
	table->last_meal = time_now();
	pthread_create(&table->dead, NULL, (void *)is_dead, table);
	eat_and_sleep(table);
}
