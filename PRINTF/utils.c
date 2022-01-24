/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:49:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/24 20:21:15 by lrondia          ###   ########.fr       */
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

int	ft_unsignedlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
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

void	add_prefix_address(t_flags *flags)
{
	ft_putstr_fd("0x", 1);
	flags->count += 2;
}

void	ft_putstrl(char *s, int len, t_flags *flags)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
		flags->count++;
	}
}

void	print_sign(t_flags *flags, int *value)
{
	if (flags->is_plus && *value >= 0)
		ft_putchar_fd('+', 1);
	else if (flags->is_space && *value >= 0)
		ft_putchar_fd(' ', 1);
	else if (*value < 0)
	{
		ft_putchar_fd('-', 1);
		*value *= -1;
	}
	flags->count++;
}

int	padding_zero(int *len, int padding)
{
	int	i;

	i = 0;
	while (*len < padding)
	{
		ft_putchar_fd('0', 1);
		(*len)++;
		i++;
	}
	return (i);
}

int	padding_space(int *len, int padding)
{
	int	i;

	i = 0;
	while (*len < padding)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
		i++;
	}
	return (i);
}
