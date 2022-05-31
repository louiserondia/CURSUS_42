/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:25:06 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/30 18:05:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sem_start(t_table *table)
{	
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_dead");
	table->sem_fork = sem_open("sem_fork", O_CREAT | O_EXCL,
			0644, table->nb_philo);
	table->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	table->sem_dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	if (table->sem_fork == SEM_FAILED || table->sem_print == SEM_FAILED
		|| table->sem_dead == SEM_FAILED)
		error_exit ("Sem_open() failed.");
}

void	ft_destroy(t_table *table)
{
	sem_close(table->sem_fork);
	sem_close(table->sem_dead);
	sem_close(table->sem_print);
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_dead");
	free (table->pid);
}

void	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		error_exit ("Incorrect number of arguments.");
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			error_exit ("Please only enter digits.");
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
	if (table->nb_philo == 0 || table->nb_philo > 2000)
		error_exit ("Incorrect number of philosophers.");
	table->time_to_die = ft_atoi_restrict(argv[2]);
	table->time_to_eat = ft_atoi_restrict(argv[3]);
	table->time_to_sleep = ft_atoi_restrict(argv[4]);
	if (argc == 6)
		table->total_meals = ft_atoi_restrict(argv[5]);
	else
		table->total_meals = -1;
	table->pid = malloc(sizeof(int) * table->nb_philo);
	if (!table->pid)
		exit (EXIT_FAILURE);
	while (i < table->nb_philo)
	{
		table->pid[i] = 0;
		i++;
	}
	sem_start(table);
	table->start_time = time_now();
}
