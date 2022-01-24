/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:50 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/24 23:58:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_char(va_list arg, t_flags *flags)
{
	check_flags('c', flags, arg);
	ft_putchar_fd(va_arg(arg, int), 1);
	flags->count++;
	check_minus('c', flags, arg);
}

#include <stdio.h>

void	conversion_str(va_list arg, t_flags *flags)
{
	char	*value;
	va_list	copy;

	va_copy(copy, arg);	
	value = va_arg(copy, char *);
	if (!value)
	{
		ft_putstr_fd("(null)", 1);
		flags->count += 6;
	}
	else
	{
		check_flags('s', flags, arg);
		if (flags->precision != -1)
			check_precision('s', flags, arg);	
		else
		{
			flags->count += ft_strlen(value);
			ft_putstr_fd(value, 1);
		}
		check_minus('s', flags, arg);
	}
}

void	conversion_int(va_list arg, t_flags *flags)
{
	int	value;
	va_list	copy;

	va_copy(copy, arg);
	check_flags('d', flags, arg);
	if (flags->precision != -1)
		check_precision('d', flags, arg);
	else
	{
		value = va_arg(copy, int);
		ft_putnbr_fd(value, 1);
		flags->count += ft_nbrlen(value);
	}
	check_minus('d', flags, arg);
}

void	conversion_unsigned(va_list arg, t_flags *flags)
{
	int	value;
	va_list	copy;

	va_copy(copy, arg);
	check_flags('u', flags, arg);
	if (flags->precision != -1)
		check_precision('u', flags, arg);
	else
	{
		value = va_arg(copy, unsigned int);
		ft_putunsigned_fd(value, 1);
		flags->count += ft_unsignedlen(value);
	}
	check_minus('u', flags, arg);
}

void	conversion_hex(va_list arg, int (*f)(int), t_flags *flags)
{
	unsigned int	value;
	va_list	copy;

	va_copy(copy, arg);
	check_flags('x', flags, arg);
	if (flags->precision != -1)
		check_precision('x', flags, arg);
	else
	{
		value = va_arg(copy, unsigned int);
		ft_puthexa_fd(value, 1, f);
		flags->count += ft_hexalen(value);
	}
	check_minus('x', flags, arg);
}

void	conversion_ptr(va_list arg, t_flags *flags)
{
	unsigned long	value;
	va_list	copy;

	va_copy(copy, arg);
	check_flags('p', flags, arg);
	if (flags->precision != -1)
		check_precision('p', flags, arg);
	else
	{
		add_prefix_address(flags);
		value = va_arg(copy, unsigned long);
		ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_strlen("ffffffffffff");
		check_minus('p', flags, arg);
	}
}

void	conversion_percent(va_list arg, t_flags *flags)
{
	check_flags('%', flags, arg);
	ft_putchar_fd('%', 1);
	flags->count++;
	check_minus('%', flags, arg);
}
