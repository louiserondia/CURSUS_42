/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:20:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/22 20:05:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;

	initialization(&table, argc, argv);
	fork_and_wait(&table);
	ft_destroy(&table);
	return (0);
}
