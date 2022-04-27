/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/27 16:50:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_restrict(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}

void	ft_printf_state(t_table *table)
{
	struct timeval time;
	int	i;

	i = 1;
	while (i <= table->nb_philo)
	{
		if (table->philo.state[i] == 0)
			printf("%d %d is thinking\n", gettimeofday(&time, NULL), i);
		else if (table->philo.state[i] == 1)
			printf("%d %d is eating\n", gettimeofday(&time, NULL), i);
		else if (table->philo.state[i] == 2)
			printf("%d %d is sleeping\n", gettimeofday(&time, NULL), i);
		i++;
	}
}
