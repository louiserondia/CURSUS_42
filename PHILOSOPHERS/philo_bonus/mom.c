/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:43:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/23 18:57:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	mom(t_table *table)
{
	int		i;
	int		status;

	i = 0;
	while (i < table->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < table->nb_philo)
			{
				kill(table->pid[i], SIGKILL);
				i++;
			}
		}
		i++;
	}
}

void	fork_and_wait(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			exit (0);
		else if (table->pid[i] == 0)
		{
			table->id = i;
			break ;
		}
		i++;
	}
	if (table->pid[table->id] == 0)
		child(table, table->id);
	else
		mom(table);
}
