/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/27 17:20:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_even_nb_philo(t_table *table, char **argv)
{
	(void) argv;	
	(void) table;	
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 4 || argc > 5)
		return (0);
	table.nb_philo = atoi(argv[1]);
	table.philo = malloc(sizeof(t_philo) * table.nb_philo);
	if (!table.philo)
		return (0);
	memset(&table, 0, sizeof(table));
	if (argc % 2 == 0)
		handle_even_nb_philo(&table, argv);
	ft_printf_state(&table);
}
