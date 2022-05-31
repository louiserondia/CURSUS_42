/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:12:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/31 13:21:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_table *table)
{
	int		i;

	i = 0;
	table->tid = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->tid)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->tid[i], NULL, (void *)thread,
				&(table->philo[i])) != 0)
			return (print_error("Pthread_create() failed."));
		i++;
	}
	return (1);
}

int	ft_create_mutexes(t_table *table)
{
	int	i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->fork)
		return (0);
	table->death = malloc(sizeof(pthread_mutex_t));
	if (!table->death)
		return (0);
	table->prints = malloc(sizeof(pthread_mutex_t));
	if (!table->prints)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (print_error("Pthread_mutex_init() failed."));
		i++;
	}
	if (pthread_mutex_init(table->prints, NULL) != 0)
		return (print_error("Pthread_mutex_init() failed."));
	if (pthread_mutex_init(table->death, NULL) != 0)
		return (print_error("Pthread_mutex_init() failed."));
	return (1);
}

int	ft_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->tid[i], NULL) != 0)
			return (print_error("Pthread_join() failed."));
		i++;
	}
	i = 0;
	if (pthread_mutex_destroy(table->prints)
		|| pthread_mutex_destroy(table->death))
		return (print_error("Pthread_mutex_destroy() failed."));
	while (i < table->nb_philo)
	{
		if (pthread_mutex_destroy(&table->fork[i]))
			return (print_error("Pthread_mutex_destroy() failed."));
		i++;
	}
	free (table->prints);
	free (table->death);
	free (table->philo);
	free (table->tid);
	free (table->fork);
	return (1);
}
