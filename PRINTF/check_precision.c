/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:33:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/22 15:24:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(char c, t_flags *flags, va_list arg)
{
	int	padding;
	
	padding = return_len(c, flags, arg);
	if (c == 's')
		check_precision_str(flags, arg);
	else if (c == 'd')
		check_precision_int(flags, arg, padding);
	else if (c == 'u')
		check_precision_unsigned(flags, arg, padding);
}

void	check_precision_str(t_flags *flags, va_list arg)
{
	char	*value;

	value = va_arg(arg, char*);
	ft_putstrl(value, flags->precision, flags);
}


#include <stdio.h>

void	check_precision_int(t_flags *flags, va_list arg, int padding)
{
	int	value;
	int	len;

	value = va_arg(arg, int);
	len = ft_nbrlen(value);
	if (len > flags->precision)
	{
		ft_putnbr_fd(value, 1);
		flags->count += ft_nbrlen(value);
	}
	else if (len <= flags->precision)
	{
		if (flags->is_plus || flags->is_space || value < 0)
		{
			print_sign(flags, &value);
			len--;
		}
		while (len < padding)
		{
			ft_putchar_fd('0', 1);
			len++;
		}
		ft_putnbr_fd(value, 1);
		flags->count += len;
	}	
}

void	check_precision_unsigned(t_flags *flags, va_list arg, int padding)
{
	int	value;
	int	len;

	value = va_arg(arg, unsigned int);
	len = ft_unsignedlen(value);
	if (len > flags->precision)
	{
		ft_putunsigned_fd(value, 1);
		flags->count += ft_unsignedlen(value);
	}
	else if (len <= flags->precision)
	{
		while (len < padding)
		{
			ft_putchar_fd('0', 1);
			len++;
		}
		ft_putunsigned_fd(value, 1);
		flags->count += len;
	}	
}
