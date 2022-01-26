/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:05:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:06:30 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_char(va_list arg, t_flags *flags)
{
	int	value;

	value = va_arg(arg, int);
	check_width(flags, 1);
	ft_putchar_fd(value, 1);
	flags->count++;
	check_minus_char(flags);
}

void	conversion_str(va_list arg, t_flags *flags)
{
	char	*value;
	int		padding;

	value = va_arg(arg, char *);
	padding = return_padding_str(flags, value);
	check_width(flags, padding);
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
	check_minus_str(flags, value);
}

void	conversion_percent(t_flags *flags)
{
	check_width(flags, 1);
	check_zero_percent(flags);
	ft_putchar_fd('%', 1);
	flags->count++;
	check_minus_percent(flags);
}
