/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:12:40 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/03 17:46:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	initialization(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	if (!parsing(argc, argv))
		return (0);
	memset(table, 0, sizeof(t_table));
	table->nb_philo = atoi(argv[1]);
	table->time_to_die = ft_atoi_restrict(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		table->nb_meals = atoi(argv[5]);
	table->fork = malloc(sizeof(int) * table->nb_philo);
	if (!table->fork)
		return (0);
	table->philo = malloc(sizeof(t_philo **) * table->nb_philo);
	if (!table->philo)
		return (0);
	while (i < table->nb_philo)
	{
		printf("ok\n");
		table->philo[i] = malloc(sizeof(t_philo *));
		if (!table->philo[i])
			return (0);
		table->philo[i]->last_meal = time_now();
		table->philo[i]->id = i;
		table->fork[i] = 0;
		table->philo[i]->table = table;
		i++;
	}
	return (1);
}
