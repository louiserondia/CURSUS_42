/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:35:41 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 19:46:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_int(t_flags *flags, long value)
{
	int	i;
	int	padding;

	i = 0;
	padding = return_padding_int(flags, value);
	if (flags->is_negative)
		padding++;
	if (flags->is_zero)
		i = padding_zero(padding, flags->width);
	flags->count += i;
}

void	check_zero_unsigned(t_flags *flags, unsigned int value)
{
	int	i;
	int	padding;

	i = 0;
	padding = return_padding_unsigned(flags, value);
	if (flags->is_zero)
		i = padding_zero(padding, flags->width);
	flags->count += i;
}

void	check_zero_hex(t_flags *flags, unsigned int value)
{
	int	i;
	int	padding;

	i = 0;
	padding = return_padding_hex(flags, value);
	if (flags->is_zero)
		i = padding_zero(padding, flags->width);
	flags->count += i;
}

void	check_zero_percent(t_flags *flags)
{
	int	i;
	int	padding;

	i = 0;
	padding = 1;
	if (flags->is_zero)
		i = padding_zero(padding, flags->width);
	flags->count += i;
}
