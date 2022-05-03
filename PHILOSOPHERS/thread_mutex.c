/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:12:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/03 17:04:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_create_threads(t_table *table)
{
	int	i;

	i = 0;
	table->tid = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->tid)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->tid[i], NULL, (void *)action, table->philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->tid[i], NULL) != 0)
			return (0);
		i++;
	}
	pthread_mutex_destroy(&table->mid);
	return (1);
}
