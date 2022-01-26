/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:33:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:29:14 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision_str(t_flags *flags, char *value)
{
	if (!value)
		ft_putstrl("(null)", flags->precision, flags);
	ft_putstrl(value, flags->precision, flags);
}

void	check_precision_int(t_flags *flags, long value)
{
	int	len;

	len = ft_nbrlen(value);
	if (len > flags->precision && value)
	{
		ft_putnbr_fd(value, 1);
		flags->count += ft_nbrlen(value);
	}
	else if (len <= flags->precision)
	{
		flags->count += len + padding_zero(len, flags->precision);
		if (flags->precision != 0)
			ft_putnbr_fd(value, 1);
	}	
}

void	check_precision_unsigned(t_flags *flags, unsigned int value)
{
	int	len;

	len = ft_unsignedlen(value);
	if (len > flags->precision && value)
	{
		ft_putunsigned_fd(value, 1);
		flags->count += ft_unsignedlen(value);
	}
	if (!value && flags->precision == 0)
		len++;
	else if (len <= flags->precision)
	{
		flags->count += len + padding_zero(len, flags->precision);
		if (flags->precision != 0)
			ft_putunsigned_fd(value, 1);
	}	
}

void	check_precision_hex(t_flags *flags, unsigned int value)
{
	int	len;

	len = ft_hexalen(value);
	if (len > flags->precision && value)
	{
		if (flags->is_x)
			ft_puthexa_fd(value, 1, ft_toupper);
		else
			ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_hexalen(value);
	}
	else if (len <= flags->precision)
	{
		flags->count += len + padding_zero(len, flags->precision);
		if (flags->precision != 0 || value != 0)
		{
			if (flags->is_x)
				ft_puthexa_fd(value, 1, ft_toupper);
			else
				ft_puthexa_fd(value, 1, ft_tolower);
		}	
	}	
}

void	check_precision_ptr(t_flags *flags, unsigned long value)
{
	int	len;

	len = ft_hexalen(value);
	if (len > flags->precision && value)
	{
		add_prefix_address(flags);
		ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_hexalen(value);
	}
	else if (len <= flags->precision)
	{
		add_prefix_address(flags);
		flags->count += len + padding_zero(len, flags->precision);
		if (flags->precision != 0 || value != 0)
			ft_puthexa_fd(value, 1, ft_tolower);
	}	
}
