/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:33:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/22 21:06:34 by lrondia          ###   ########.fr       */
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
	else if (c == 'x')
		check_precision_hex(flags, arg, padding);
}

void	check_precision_str(t_flags *flags, va_list arg)
{
	char	*value;

	value = va_arg(arg, char*);
	ft_putstrl(value, flags->precision, flags);
}

void	check_precision_int(t_flags *flags, va_list arg, int padding)
{
	int	value;
	int	len;

	value = va_arg(arg, int);
	len = ft_nbrlen(value);
	if (len > flags->precision && value)
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
		if(flags->precision != 0 || value != 0)
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
	if (len > flags->precision && value)
	{
		ft_putunsigned_fd(value, 1);
		flags->count += ft_unsignedlen(value);
	}
	if (!value && flags->precision == 0)
		len++;
	else if (len <= flags->precision )
	{
		while (len < padding)
		{
			ft_putchar_fd('0', 1);
			len++;
		}
		if (flags->precision != 0 && value)
			ft_putunsigned_fd(value, 1);
		flags->count += len;
	}	
}

void	check_precision_hex(t_flags *flags, va_list arg, int padding)
{
	int	value;
	int	len;

	value = va_arg(arg, unsigned int);
	len = ft_hexalen(value);
	if (len > flags->precision && value)
	{
		if (flags->is_X)
			ft_puthexa_fd(value, 1, ft_toupper);
		else
			ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_hexalen(value);
	}
	else if (len <= flags->precision)
	{
		while (len < padding)
		{
			ft_putchar_fd('0', 1);
			len++;
		}
		if(flags->precision != 0 || value != 0)
		{
			if (flags->is_X)
				ft_puthexa_fd(value, 1, ft_toupper);
			else
				ft_puthexa_fd(value, 1, ft_tolower);
		}	
		flags->count += len;
	}	
}
