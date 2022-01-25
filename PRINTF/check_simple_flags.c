/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/25 18:41:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char c, t_flags *flags, va_list copy)
{
	va_list	copy_flag;

	va_copy(copy_flag, copy);
	check_width(c, flags, copy_flag);
	check_sharp(c, flags, copy_flag);
	check_plus(c, flags, copy_flag);
	check_space(c, flags, copy_flag);
	check_zero(c, flags, copy_flag);
}

void	check_sharp(char c, t_flags *flags, va_list copy)
{
	if (c == 'x' && flags->is_sharp && va_arg(copy, int))
		add_prefix_address(flags);
}

void	check_plus(char c, t_flags *flags, va_list copy)
{
	int		value;

	value = va_arg(copy, int);
	if (c == 'd' && flags->is_plus && value >= 0)
	{
		flags->count++;
		ft_putchar_fd('+', 1);
	}
}

void	check_space(char c, t_flags *flags, va_list copy)
{
	int		value;

	value = va_arg(copy, int);
	if ((c == 'd' || c == 'i') && flags->is_space && !flags->is_plus)
	{
		flags->count++;
		ft_putchar_fd(' ', 1);
	}
}


void	check_width(char c, t_flags *flags, va_list copy)
{
	int		i;
	int		padding;
	int		width;
	
	i = 0;
	width = flags->width;
	padding = return_padding(c, flags, copy);
	if (flags->width <= 0 || flags->is_zero || flags->is_minus)
		return ;
	while (i < width - padding) 
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (width >= padding)
		flags->count += width - padding;
}
