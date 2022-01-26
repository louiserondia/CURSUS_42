/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:50 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:06:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_int(va_list arg, t_flags *flags)
{
	long	value;
	int		padding;

	value = va_arg(arg, int);
	padding = return_padding_int(flags, value);
	if (flags->precision == 0 && !value)
		padding--;
	if (value < 0)
		flags->is_negative = 1;
	check_width(flags, padding);
	check_plus(flags, value);
	check_space(flags, value);
	if (flags->is_negative)
		print_sign(flags, &value);
	check_zero_int(flags, value);
	if (flags->precision != -1)
		check_precision_int(flags, value);
	else
	{
		ft_putnbr_fd(value, 1);
		flags->count += ft_nbrlen(value);
	}
	check_minus_int(flags, value);
}

void	conversion_unsigned(va_list arg, t_flags *flags)
{
	int	value;
	int	padding;

	value = va_arg(arg, unsigned int);
	padding = return_padding_unsigned(flags, value);
	if (flags->precision == 0 && !value)
		padding--;
	check_width(flags, padding);
	check_zero_unsigned(flags, value);
	if (flags->precision != -1)
		check_precision_unsigned(flags, value);
	else
	{
		ft_putunsigned_fd(value, 1);
		flags->count += ft_unsignedlen(value);
	}
	check_minus_unsigned(flags, value);
}

void	conversion_hex(va_list arg, int (*f)(int), t_flags *flags)
{
	unsigned int	value;
	int				padding;

	value = va_arg(arg, unsigned int);
	padding = return_padding_hex(flags, value);
	if (flags->precision == 0 && !value)
		padding--;
	check_width(flags, padding);
	check_sharp(flags, value);
	check_zero_hex(flags, value);
	if (flags->precision != -1)
		check_precision_hex(flags, value);
	else
	{
		ft_puthexa_fd(value, 1, f);
		flags->count += ft_hexalen(value);
	}
	check_minus_hex(flags, value);
}

void	conversion_ptr(va_list arg, t_flags *flags)
{
	unsigned long	value;
	int				padding;

	value = va_arg(arg, unsigned long);
	padding = return_padding_ptr(flags, value);
	check_width(flags, padding);
	if (flags->precision != -1)
		check_precision_ptr(flags, value);
	else
	{
		add_prefix_address(flags);
		ft_puthexa_fd(value, 1, ft_tolower);
		flags->count += ft_hexalen(value);
	}
	check_minus_ptr(flags, value);
}
