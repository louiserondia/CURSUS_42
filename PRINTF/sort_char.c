/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:20:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/27 15:46:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sort_char(char c, va_list arg, t_flags *flags)
{
	if (flags->precision != -1 && flags->is_zero)
		flags->is_zero = 0;
	if (c == 'c')
		conversion_char(arg, flags);
	else if (c == 's')
		conversion_str(arg, flags);
	else if (c == 'd' || c == 'i')
		conversion_int(arg, flags);
	else if (c == 'u')
		conversion_unsigned(arg, flags);
	else if (c == 'p')
		conversion_ptr(arg, flags);
	else if (c == 'x')
		conversion_hex(arg, ft_tolower, flags);
	else if (c == 'X')
		conversion_hex(arg, ft_toupper, flags);
	else
		conversion_percent(flags);
}

void	set_flag(char c, t_flags *flags)
{
	if (c == '#')
		flags->is_sharp = 1;
	if (c == '+')
		flags->is_plus = 1;
	if (c == ' ')
		flags->is_space = 1;
	if (c == '-')
		flags->is_minus = 1;
	if (c == '0')
		flags->is_zero = 1;
	if (c == '.')
		flags->precision = 0;
}
