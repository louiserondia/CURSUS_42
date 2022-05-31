/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:12:40 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/30 17:32:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (print_error("Incorrect number of arguments."));
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (print_error("Please only enter digits."));
		i++;
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philo)
		return (0);
	while (i < table->nb_philo)
	{
		table->philo[i].nb_meals = 0;
		table->philo[i].last_meal = time_now();
		table->philo[i].id = i;
		table->philo[i].table = table;
		i++;
	}
	return (1);
}

int	initialization(t_table *table, int argc, char **argv)
{
	if (!parsing(argc, argv))
		return (0);
	memset(table, 0, sizeof(t_table));
	table->nb_philo = ft_atoi_restrict(argv[1]);
	if (table->nb_philo == 0 || table->nb_philo > 2000)
		return (print_error("Incorrect number of philosophers."));
	table->time_to_die = ft_atoi_restrict(argv[2]);
	table->time_to_eat = ft_atoi_restrict(argv[3]);
	table->time_to_sleep = ft_atoi_restrict(argv[4]);
	if (argc == 6)
		table->total_meals = ft_atoi_restrict(argv[5]);
	else
		table->total_meals = -1;
	if (!init_philo(table))
		return (0);
	table->start_time = time_now();
	return (1);
}
