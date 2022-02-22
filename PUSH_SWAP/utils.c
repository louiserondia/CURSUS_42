/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/22 16:44:42 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_restrict(char *str)
{
	int	i;
	int	s;
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
	}
	if (str[i] != '\0')
		ft_exit("Error\n");
	if (res > 2147483647 || res < -2147483648 || (res == -1 && s == 1))
		ft_exit("Error\n");
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