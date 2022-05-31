/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/12 16:16:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int *count, long long int i)
{
	if (i < 0)
	{
		(*count)++;
		write (1, "-", 1);
		i *= -1;
	}
	if (i >= 10)
	{
		ft_putnbr(count, i / 10);
		ft_putnbr(count, i % 10);
	}
	else
	{
		(*count)++;
		i += 48;
		write(1, &i, 1);
	}
}

void	ft_puthexa(int *count, unsigned long int i, char c)
{
	char	*base;
	char	*maj_base;

	base = "0123456789abcdef";
	maj_base = "0123456789ABCDEF";
	if (c == 'p')
	{
		*count += 2;
		c = 'a';
		write (1, "0x", 2);
	}
	if (i >= 16)
	{
		ft_puthexa(count, i / 16, c);
		ft_puthexa(count, i % 16, c);
	}
	else
	{
		(*count)++;
		if (c == 'X')
			write(1, &maj_base[i], 1);
		else
			write(1, &base[i], 1);
	}
}

void	ft_putstr(int *count, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{	
		(*count)++;
		write(1, &str[i], 1);
		i++;
	}
}

void	check_conversion(int *count, char c, va_list arg)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(count, va_arg(arg, int));
	else if (c == 'u')
		ft_putnbr(count, va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_puthexa(count, va_arg(arg, unsigned int), c);
	else if (c == 's')
		ft_putstr(count, va_arg(arg, char *));
	else if (c == 'c')
	{
		(*count)++;
		c = va_arg(arg, int);
		write(1, &c, 1);
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		count++;
	}
}

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_conversion(&count, format[i], arg);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(arg);
	return (count);
}
