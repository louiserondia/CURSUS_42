/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:35:41 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/25 15:29:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero(char c, t_flags *flags, va_list copy)
{
	if (flags->is_zero && flags->precision == -1)
	{
		if (c == 'd')
			check_zero_int(flags, copy);
		else if (c == 'u')
			check_zero_unsigned(flags, copy);
		else if (c == 'x')
			check_zero_hex(flags, copy);
		else if (c == '%')
			check_zero_percent(flags);
	}
}

void	check_zero_int(t_flags *flags, va_list copy)
{
	int		i;
	int		len;
	int		value;

	value = va_arg(copy, int);
	len = ft_nbrlen(value);
	i =	padding_zero(&len, flags->width);
	flags->count += i;
}

void	check_zero_unsigned(t_flags *flags, va_list copy)
{
	int				i;
	int				len;
	unsigned int	value;

	value = va_arg(copy, unsigned int);
	len = ft_unsignedlen(value);
	i =	padding_zero(&len, flags->width);
	flags->count += i;
}


void	check_zero_hex(t_flags *flags, va_list copy)
{
	int				i;
	int				len;
	unsigned int	value;

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
