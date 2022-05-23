/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:25:06 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/23 18:57:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sem_start(t_table *table)
{	
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	table->sem_fork = sem_open("sem_fork", O_CREAT | O_EXCL,
			0644, table->nb_philo);
	table->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 0644);
	table->sem_dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644);
}

void	ft_destroy(t_table *table)
{
	sem_close(table->sem_fork);
	sem_close(table->sem_dead);
	sem_close(table->sem_print);
	free (table->pid);
}

void	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		exit (0);
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			exit (0);
		i++;
	}
}

void	initialization(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	parsing(argc, argv);
	memset(table, 0, sizeof(t_table));
	table->nb_philo = ft_atoi_restrict(argv[1]);
	table->time_to_die = ft_atoi_restrict(argv[2]);
	table->time_to_eat = ft_atoi_restrict(argv[3]);
	table->time_to_sleep = ft_atoi_restrict(argv[4]);
	if (argc == 6)
		table->total_meals = ft_atoi_restrict(argv[5]);
	table->pid = malloc(sizeof(int) * table->nb_philo);
	if (!table->pid)
		exit (0);
	while (i < table->nb_philo)
	{
		table->pid[i] = 0;
		i++;
	}
	sem_start(table);
	table->start_time = time_now();
}
