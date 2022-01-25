/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:05:36 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/25 18:41:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus_char(t_flags *flags)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_str(t_flags *flags, va_list copy)
{
	int		i;
	int		len;

	i = 0;
	len = return_padding('s', flags, copy);
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_int(t_flags *flags, va_list copy)
{
	int		i;
	int		len;

	i = 0;
	len = return_padding('d', flags, copy);
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_unsigned(t_flags *flags,  va_list copy)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding('u', flags, copy);
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_hex(t_flags *flags,  va_list copy)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding('x', flags, copy);
	if (flags->is_sharp)
		len += 2;
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_ptr(t_flags *flags,  va_list copy)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding('p', flags, copy);
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_percent(t_flags *flags)
{
	int	i;
	int	len;
	
	i = 0;
	len = 1;
	if (flags->is_minus)
		i =	padding_space(&len, flags->width);
	flags->count += i;
}
