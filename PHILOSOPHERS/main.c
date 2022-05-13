/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/13 20:15:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!initialization(&table, argc, argv))
		return (1);
	if (!ft_create_mutexes(&table))
		return (0);
	if (!ft_create_threads(&table))
		return (1);
	is_dead(&table);
	if (!ft_destroy(&table))
		return (1);
	return (0);
}
