/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:05:36 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/24 23:14:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	check_minus(char c, t_flags *flags, va_list arg)
{
	if (c == 'c')
		check_minus_char(flags);
	else if (c == 's')
		check_minus_str(flags, arg);
	if (c == 'd')
		check_minus_int(flags, arg);
	else if (c == 'u')
		check_minus_unsigned(flags, arg);
	else if (c == 'x')
		check_minus_hex(flags, arg);
	else if (c == 'p')
		check_minus_ptr(flags, arg);
	else if (c == '%')
		check_minus_percent(flags);
}

void	check_minus_char(t_flags *flags)
{
	int		i;
	int		len;

	len = 1;
	i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_str(t_flags *flags, va_list arg)
{
	int		i;
	int		len;
	char	*value;

	value = va_arg(arg, char *);
	len = 1;
	i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_int(t_flags *flags, va_list arg)
{
	int		i;
	int		len;
	int		value;

	value = va_arg(arg, int);
	len = ft_nbrlen(value);
	if (flags->is_plus || flags->is_space)
		len++;
	i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_unsigned(t_flags *flags, va_list arg)
{
	int				i;
	int				len;
	unsigned int	value;

	value = va_arg(arg, unsigned int);
	len = ft_unsignedlen(value);
	i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_hex(t_flags *flags, va_list arg)
{
	int				i;
	int				len;
	unsigned int	value;

	value = va_arg(arg, unsigned int);
	len = ft_hexalen(value);
	if (flags->is_sharp)
		len += 2;
	i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_ptr(t_flags *flags, va_list arg)
{
	int				i;
	int				len;
	unsigned long	value;

	value = va_arg(arg, unsigned long);
	len = ft_strlen("0xffffffffffff");
	i =	padding_space(&len, flags->width);
	flags->count += i;
}

void	check_minus_percent(t_flags *flags)
{
	int		i;
	int		len;
	
	len = 1;
	i =	padding_space(&len, flags->width);
	flags->count += i;
}
