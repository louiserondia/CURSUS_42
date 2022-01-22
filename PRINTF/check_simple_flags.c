/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/22 21:00:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char c, t_flags *flags, va_list arg)
{
	check_width(c, flags, arg);
	check_sharp(c, flags, arg);
	check_plus(c, flags, arg);
	check_space(c, flags, arg);
}

void	check_sharp(char c, t_flags *flags, va_list arg)
{
	va_list	copy;

	va_copy(copy, arg);
	if (c == 'x' && flags->is_sharp && va_arg(copy, int))
		add_prefix_address(flags);
}

void	check_plus(char c, t_flags *flags, va_list arg)
{
	va_list	copy;
	int		value;

	va_copy(copy, arg);
	value = va_arg(copy, int);
	if (c == 'd' && flags->is_plus && value >= 0)
	{
		flags->count++;
		ft_putchar_fd('+', 1);
	}
}

void	check_space(char c, t_flags *flags, va_list arg)
{
	va_list	copy;
	int		value;

	va_copy(copy, arg);
	value = va_arg(copy, int);
	if ((c == 'd' || c == 'i') && flags->is_space && !flags->is_plus)
	{
		flags->count++;
		ft_putchar_fd(' ', 1);
	}
}

void	check_width(char c, t_flags *flags, va_list arg)
{
	int		i;
	int		len;
	int		width;
	
	i = 0;
	width = flags->width;
	len = return_len(c, flags, arg);
	if (flags->width <= 0 || flags->is_zero || flags->is_minus)
		return ;
	while (i < width - len) 
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (width >= len)
		flags->count += width - len;
}

