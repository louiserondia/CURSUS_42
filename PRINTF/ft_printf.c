/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:02:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 17:12:06 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

void	check_char(const char *format, va_list arg, int *i, t_flags *flags)
{
	char	c;

	c = format[*i];
	while (check_conversion(c))
	{
		if (c == '#' || c == '+' || c == ' ' || c == '.' || c == '-'
			|| c == '*' || c == '0')
		{
			set_flag(c, flags);
			(*i)++;
			c = format[*i];
		}
		else if (c >= '1' && c <= '9')
		{
			flags->width = 0;
			while (c >= '0' && c <= '9')
			{
				flags->width = flags->width * 10 + c - '0';
				(*i)++;
				c = format[*i];
			}
		}
	}
	
	sort_char(c, arg, flags);
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
	flags.width = 0;
	flags.count = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	t_flags	flags;

	i = 0;
	va_start(arg, format);
	flags = init_flags();
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_char(format, arg, &i, &flags);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			flags.count++;
		}
		i++;
	}
	return (flags.count);
}
