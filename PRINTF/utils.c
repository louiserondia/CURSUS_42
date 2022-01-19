/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:49:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 17:27:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_fd(unsigned long n, int fd, int (*f)(int))
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthexa_fd(n / 16, fd, f);
		ft_putchar_fd(f(base[n % 16]), fd);
	}
	else
		ft_putchar_fd(f(base[n]), fd);
}

int	ft_nbrlen(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_hexalen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunsigned_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
}

void	add_prefix_address(t_flags *flags)
{
	ft_putstr_fd("0x", 1);
	flags->count += 2;
}
