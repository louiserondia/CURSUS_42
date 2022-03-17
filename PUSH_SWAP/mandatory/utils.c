/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:28:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}		
	exit (0);
}

int	ft_atoi_restrict(char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	res = 0;
	s = 1;
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res > INT_MAX && !(res == (long)INT_MAX + 1 && s == -1))
			ft_exit("Error\n");
	}
	if (str[i] != '\0')
		ft_exit("Error\n");
	res *= s;
	return (res);
}

size_t	same_str(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[j] == '0' && s1[j])
		j++;
	while (s2[k] == '0' && s2[k])
		k++;
	while (s1[i + j] == s2[i + k] && s1[i + j] && s2[i + k])
		i++;
	if (i == ft_strlen(s1) - j && i == ft_strlen(s2) - k)
		return (1);
	return (0);
}
