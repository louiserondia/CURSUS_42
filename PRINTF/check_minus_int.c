/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:05:36 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:04:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus_int(t_flags *flags, long value)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding_int(flags, value);
	if (!flags->is_minus)
		return ;
	if (flags->is_negative)
		len++;
	if (value < 0 && len == flags->precision)
		len++;
	if (!value && flags->precision == 0)
		len = 0;
	i = padding_space(len, flags->width);
	flags->count += i;
}

void	check_minus_unsigned(t_flags *flags, unsigned int value)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding_unsigned(flags, value);
	if (!value && flags->precision == 0)
		len = 0;
	if (flags->is_minus)
		i = padding_space(len, flags->width);
	flags->count += i;
}

void	check_minus_hex(t_flags *flags, unsigned int value)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding_hex(flags, value);
	if (!value && flags->precision == 0)
		len = 0;
	if (flags->is_sharp)
		len += 2;
	if (flags->is_minus)
		i = padding_space(len, flags->width);
	flags->count += i;
}

void	check_minus_ptr(t_flags *flags, unsigned long value)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding_ptr(flags, value);
	if (flags->is_minus)
		i = padding_space(len, flags->width);
	flags->count += i;
}
