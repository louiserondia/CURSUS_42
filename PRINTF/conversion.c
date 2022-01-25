/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:50 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/25 18:10:06 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_char(va_list arg, t_flags *flags)
{
	int	value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(arg, int);
	check_flags('c', flags, copy);
	ft_putchar_fd(value, 1);
	flags->count++;
	check_minus_char(flags);
}

void	conversion_str(va_list arg, t_flags *flags)
{
	char	*value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(arg, char *);
	check_flags('s', flags, copy);
	if (flags->precision != -1)
		check_precision_str(flags, value);	
	else if (!value)
	{
		ft_putstr_fd("(null)", 1);
		flags->count += 6;
	}
	else
	{
		flags->count += ft_strlen(value);
		ft_putstr_fd(value, 1);
	}
	check_minus_str(flags, copy);
}

void	conversion_int(va_list arg, t_flags *flags)
{
	int	value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(arg, int);
	check_flags('d', flags, copy);
	if (flags->precision != -1)
		check_precision_int(flags, value);
	else
	{
		ft_putnbr_fd(value, 1);
		flags->count += ft_nbrlen(value);
	}
	check_minus_int(flags, copy);
}

void	conversion_unsigned(va_list arg, t_flags *flags)
{
	int	value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(arg, unsigned int);
	check_flags('u', flags, copy);
	if (flags->precision != -1)
		check_precision_unsigned(flags, value);
	else
	{
		ft_putunsigned_fd(value, 1);
		flags->count += ft_unsignedlen(value);
	}
	check_minus_unsigned(flags, copy);
}

void	conversion_hex(va_list arg, int (*f)(int), t_flags *flags)
{
	unsigned int	value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(arg, unsigned int);
	check_flags('x', flags, copy);
	if (flags->precision != -1)
		check_precision_hex(flags, value);
	else
	{
		ft_puthexa_fd(value, 1, f);
		flags->count += ft_hexalen(value);
	}
	check_minus_hex(flags, copy);
}

void	conversion_ptr(va_list arg, t_flags *flags)
{
	unsigned long	value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(arg, unsigned long);
	check_flags('p', flags, copy);
	if (flags->precision != -1)
		check_precision_ptr(flags, value);
	else
	{
		add_prefix_address(flags);
		ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_hexalen(value);
	}
	check_minus_ptr(flags, copy);
}

void	conversion_percent(va_list arg, t_flags *flags)
{
	va_list	copy;

	va_copy(copy, arg);
	check_flags('%', flags, copy);
	ft_putchar_fd('%', 1);
	flags->count++;
	check_minus_percent(flags);
}
