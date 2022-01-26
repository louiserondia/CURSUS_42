/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 19:45:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_sharp(t_flags *flags, unsigned int value)
{
	if (flags->is_sharp && value)
		add_prefix_address(flags);
}

void	check_plus(t_flags *flags, int value)
{
	if (flags->is_plus && value >= 0)
	{
		flags->count++;
		ft_putchar_fd('+', 1);
	}
}

void	check_space(t_flags *flags, int value)
{
	if (flags->is_space && !flags->is_plus && value >= 0)
	{
		flags->count++;
		ft_putchar_fd(' ', 1);
	}
}

void	check_width(t_flags *flags, int padding)
{
	if (flags->is_negative && flags->precision != -1 && flags->width >= padding
		&& flags->precision >= padding)
		padding++;
	if (flags->width >= padding && !flags->is_minus && !flags->is_zero)
	{
		padding_space(padding, flags->width);
		flags->count += flags->width - padding;
	}
}
