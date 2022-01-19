/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:20:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 12:15:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort_char(char c, va_list arg, t_flags *flags)
{
	if (c == 'c')
		return (conversion_char(arg));
	else if (c == 's')
		return (conversion_str(arg));
	else if (c == 'd' || c == 'i')
		return (conversion_int(arg, flags));
	else if (c == 'u')
		return (conversion_unsigned(arg));
	else if (c == 'p')
		return (conversion_ptr(arg));
	else if (c == 'x')
		return (conversion_hex(arg, ft_tolower, flags));
	else if (c == 'X')
		return (conversion_hex(arg, ft_toupper, flags));
	else if (c == '%')
		return (conversion_percent());
	else
		return (0);
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
		flags->is_dot = 1;
	if (c == '*')
		flags->is_wildcard = 1;
	if (c >= '1' && c <= '9')
		flags->is_width = 1;
	debug(flags);
}
