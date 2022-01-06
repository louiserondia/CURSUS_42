/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:41:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/06 18:59:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_modulo(int nb)
{
	int	sign;

	sign = 1;
	if (nb == INT_MIN)
		return (8 + '0');
	if (nb < 0)
	{	
		nb *= -1;
		sign *= -1;
	}
	return (nb % 10 + '0');
}

static int	ft_devide(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	ln;
	int		devide;
	char	*res;
	int		i;

	ln = n;
	devide = ft_devide(ln);
	res = malloc(sizeof(char) * (devide + 1));
	i = devide - 1;
	if (!res)
		return (NULL);
	if (ln < 0)
		res[0] = '-';
	if (ln == 0)
		res[0] = '0';
	res[i + 1] = '\0';
	while (i >= 0 && ln != 0)
	{
		res[i] = ft_modulo(ln);
		ln /= 10;
		i--;
	}
	return (res);
}
