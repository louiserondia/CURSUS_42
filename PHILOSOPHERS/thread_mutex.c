/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:12:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/04 18:59:18 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_table *table)
{
	int		i;
	t_philo	*copy;

	i = 0;
	table->tid = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->tid)
		return (0);
	while (i < table->nb_philo)
	{
		copy = malloc(sizeof(t_philo));
		*copy = table->philo[i];
		if (pthread_create(&table->tid[i], NULL, (void *)thread,
				&(table->philo[i])) != 0)
			return (0);
		i++;
		free(copy);
	}
	i = 0;
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
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
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
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&table->prints[0], NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->prints[1], NULL) != 0)
		return (0);
	return (1);
}

void	mutex_for_prints(t_philo *philo, pthread_mutex_t mutex, char *str)
{
	int		phi;
	time_t	now;

	phi = philo->id;
	now = time_now();
	pthread_mutex_lock(&mutex);
	printf("%ld %d %s\n", now, phi, str);
	pthread_mutex_unlock(&mutex);
}
