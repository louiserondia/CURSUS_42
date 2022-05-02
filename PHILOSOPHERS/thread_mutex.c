/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:12:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/02 17:06:37 by lrondia          ###   ########.fr       */
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
		table->current_philo = i;
		if (pthread_create(&table->tid[i], NULL, (void *)action, table) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_create_mutexes(t_table *table)
{
	int	i;

	i = 0;
	table->mid = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->mid)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->mid[i], NULL) != 0)
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
		pthread_mutex_destroy(&table->mid[i]);
		i++;
	}
	return (1);
}

void	ft_lock_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_lock(&table->mid[i]);
		i++;
	}
}

void	ft_unlock_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_unlock(&table->mid[i]);
		i++;
	}
}
