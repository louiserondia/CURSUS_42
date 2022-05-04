/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/04 16:27:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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

time_t	time_now(void)
{
	time_t			res;
	struct timeval	time;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}

int	is_dead(t_table *table)
{
	int		i;
	time_t	now;

	while (1)
	{
		i = 0;
		now = time_now();
		while (i < table->nb_philo)
		{
			if (now > table->philo[i].last_meal + table->time_to_die)
			{
				printf("%ld %d is dead\n", now, i);
				table->someone_died = 1;
				return (0);
			}
			i++;
		}
	}
	return (1);
}

void	ft_printf_state(t_table *table)
{
	int		i;
	time_t	res;

	i = 0;
	res = time_now();
	while (i < table->nb_philo)
	{
		if (table->philo[i].state == 0)
			printf("%ld %d is thinking\n", res, i);
		else if (table->philo[i].state == 1)
			printf("%ld %d is eating\n", res, i);
		else if (table->philo[i].state == 2)
			printf("%ld %d is sleeping\n", res, i);
		i++;
	}
}
