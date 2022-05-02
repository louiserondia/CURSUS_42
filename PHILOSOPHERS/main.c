/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/02 14:10:35 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_even_nb_philo(t_table *table)
{
	(void) table;
}

void	*action(t_table *table)
{
	int	i;
	pthread_t	res;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_lock(&table->mid[i]);
		i++;
	}
	res = pthread_self();
	if (pthread_equal(res, table->tid[1]))
		printf("ok\n");
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_unlock(&table->mid[i]);
		i++;
	}
	(void) table;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!initialization(&table, argc, argv))
		return (1);
	if (table.nb_philo % 2 == 0)
		handle_even_nb_philo(&table);
	if (!ft_create_mutexes(&table))
		return (1);
	if (!ft_create_threads(&table))
		return (1);
	if (!ft_destroy(&table))
		return (1);
	ft_printf_state(&table);
	return (0);
}
