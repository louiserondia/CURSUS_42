/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:02:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 11:56:31 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversion(char c)
{
	if (!(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%'))
		return (1);
	return (0);
}

int	check_char(const char *format, va_list arg, int *i, t_flags *flags)
{
	char	c;

	c = format[*i];
	(void)i;
	while (check_conversion(c))
	{
		if (c == '#' || c == '+' || c == ' ' || c == '.' || c == '-'
			|| c == '*' || (c >= '0' && c <= '9'))
			set_flag(c, flags);
		(*i)++;
		c = format[*i];
	}
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (sort_char(c, arg, flags));
	else
		return (0);
}

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.is_sharp = 0;
	flags.is_plus = 0;
	flags.is_space = 0;
	flags.is_minus = 0;
	flags.is_zero = 0;
	flags.is_dot = 0;
	flags.is_wildcard = 0;
	flags.is_width = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;
	t_flags	flags;

	i = 0;
	count = 0;
	va_start(arg, format);
	flags = init_flags();
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += check_char(format, arg, &i, &flags);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
