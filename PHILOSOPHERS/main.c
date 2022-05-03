/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/03 17:02:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_even_nb_philo(t_table *table)
{
	(void) table;
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!initialization(&table, argc, argv))
		return (1);
	if (table.nb_philo % 2 == 0)
		handle_even_nb_philo(&table);
	if (pthread_mutex_init(&table.mid, NULL) != 0)
		return (0);
	if (!ft_create_threads(&table))
		return (1);
	if (!is_dead(&table))
		return (1);
	if (!ft_destroy(&table))
		return (1);
	// ft_printf_state(&table);
	return (0);
}
