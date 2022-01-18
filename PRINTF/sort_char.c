/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:20:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/18 17:08:05 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort_char(char c, va_list arg, va_list copy)
{
	if (c == 'c')
		(ft_putchar_fd(va_arg(arg, int), 1));
	else if (c == 's')
		return (check_string(arg));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_puthexa_fd(va_arg(arg, unsigned long), 1, ft_tolower) + 2);
	}
	else if (c == 'u')
		ft_putunsigned_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		return (ft_puthexa_fd(va_arg(arg, unsigned int), 1, ft_tolower));
	else if (c == 'X')
		return (ft_puthexa_fd(va_arg(arg, unsigned int), 1, ft_toupper));
	else if (c == '%')
		ft_putchar_fd('%', 1);
	if (c == 'c' || c == '%')
		return (1);
	if (c == 'd' || c == 'i')
		return (ft_nbrlen(va_arg(copy, int)));
	if (c == 'u')
		return (ft_nbrlen(va_arg(copy, unsigned int)));
	return (0);
}

int	sort_char(char c, va_list arg, va_list copy, t_flags *flags)
{
	if (c == 'c')
		return (conversion_char(arg));
	else if (c == 's')
		return (conversion_str(arg));
	else if (c == 'd' || c == 'i')
		return (conversion_int(arg));
	else if (c == 'u')
		return (conversion_unsigned(arg));
	else if (c === 'p')
		return (conversion_ptr(arg));
	else if (c == 'x')
		return (conversion_hex(arg, ft_tolower));
	else if (c == 'X')
		return (conversion_hex(arg, ft_toupper));
	else if (c == '%')
		return (conversion_percent());
}

void	sort_simple_flag(char c, t_flags *flags)
{
	if (c == '#')
		flags->is_sharp = 1;
	if (c == '+')
		flags->is_plus = 1;
	if (c == ' ')
		flags->is_space = 1;
	debug(flags);
}

// void	sort_complex_flag(char c, va_list arg)
// {

// }
