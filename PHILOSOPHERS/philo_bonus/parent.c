/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:43:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/30 17:48:46 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	parent(t_table *table)
{
	int		i;
	int		j;
	int		status;

	i = 0;
	while (i < table->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			j = 0;
			while (j < table->nb_philo)
			{
				kill(table->pid[j], SIGKILL);
				j++;
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
			error_exit ("Fork() failed.");
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
		parent(table);
}
