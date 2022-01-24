/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:33:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/24 21:29:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(char c, t_flags *flags, va_list arg)
{
	if (c == 's')
		check_precision_str(flags, arg);
	else if (c == 'd')
		check_precision_int(flags, arg);
	else if (c == 'u')
		check_precision_unsigned(flags, arg);
	else if (c == 'x')
		check_precision_hex(flags, arg);
	else if (c == 'p')
		check_precision_ptr(flags, arg);
}

void	check_precision_str(t_flags *flags, va_list arg)
{
	char	*value;

	value = va_arg(arg, char*);
	ft_putstrl(value, flags->precision, flags);
}

void	check_precision_int(t_flags *flags, va_list arg)
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
		padding_zero(&len, flags->precision);
		if(flags->precision != 0 || value != 0)
			ft_putnbr_fd(value, 1);
		flags->count += len;
	}	
}

void	check_precision_unsigned(t_flags *flags, va_list arg)
{
	unsigned int	value;
	int				len;

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
		padding_zero(&len, flags->precision);
		if (flags->precision != 0 && value)
			ft_putunsigned_fd(value, 1);
		flags->count += len;
	}	
}

void	check_precision_hex(t_flags *flags, va_list arg)
{
	unsigned int	value;
	int				len;

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
		padding_zero(&len, flags->precision);
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

void	check_precision_ptr(t_flags *flags, va_list arg)
{
	unsigned long	value;
	int				len;

	
	value = va_arg(arg, unsigned long);
	len = ft_strlen("ffffffffffff");
	if (len > flags->precision && value)
	{
		add_prefix_address(flags);
		ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_strlen("ffffffffffff");
	}
	else if (len <= flags->precision)
	{
		add_prefix_address(flags);
		padding_zero(&len, flags->precision);
		if(flags->precision != 0 || value != 0)
				ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += len;
	}	
}
