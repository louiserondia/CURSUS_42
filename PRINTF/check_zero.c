/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:35:41 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/24 20:06:30 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero(char c, t_flags *flags, va_list arg)
{
	if (flags->is_zero && flags->precision == -1)
	{
		if (c == 'd')
			check_zero_int(flags, arg);
		else if (c == 'u')
			check_zero_unsigned(flags, arg);
		else if (c == 'x')
			check_zero_hex(flags, arg);
		else if (c == '%')
			check_zero_percent(flags);
	}
}

void	check_zero_int(t_flags *flags, va_list arg)
{
	int		i;
	int		len;
	int		value;
	va_list	copy;

	va_copy(copy, arg);
	value = va_arg(copy, int);
	len = ft_nbrlen(value);
	i =	padding_zero(&len, flags->width);
	flags->count += i;
}

void	check_zero_unsigned(t_flags *flags, va_list arg)
{
	int				i;
	int				len;
	unsigned int	value;
	va_list			copy;

	va_copy(copy, arg);
	value = va_arg(copy, unsigned int);
	len = ft_unsignedlen(value);
	i =	padding_zero(&len, flags->width);
	flags->count += i;
}


void	check_zero_hex(t_flags *flags, va_list arg)
{
	int				i;
	int				len;
	unsigned int	value;
	va_list			copy;

	va_copy(copy, arg);
	value = va_arg(copy, unsigned int);
	len = ft_hexalen(value);
	i =	padding_zero(&len, flags->width);
	flags->count += i;
}

void	check_zero_percent(t_flags *flags)
{
	int	i;
	int	len;

	len = 1;
	i =	padding_zero(&len, flags->width);
	flags->count += i;
}
