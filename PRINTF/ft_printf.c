/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:02:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/27 15:47:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conversion(char c, t_flags *flags)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		if (c == 'X')
			flags->is_x_maj = 1;
		return (1);
	}
	return (0);
}

int	is_flag(char c)
{
	if (c == '#' || c == '+' || c == ' ' || c == '.' || c == '-'
		|| c == '*' || c == '0')
		return (1);
	return (0);
}

void	add_flags_digit(const char *c, int *i, int *digit)
{
	while (ft_isdigit(c[*i]))
	{
		*digit = *digit * 10 + c[*i] - '0';
		(*i)++;
	}
}

void	check_char(const char *c, va_list arg, int *i, t_flags *flags)
{
	while (!is_conversion(c[*i], flags))
	{
		if (is_flag(c[*i]))
		{
			set_flag(c[*i], flags);
			(*i)++;
		}
		if (flags->precision == 0)
			add_flags_digit(c, i, &flags->precision);
		else if (c[*i] >= '1' || c[*i] <= '9')
		{
			flags->width = 0;
			add_flags_digit(c, i, &flags->width);
		}
	}
	sort_char(c[*i], arg, flags);
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
			reset_flags(&flags);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			flags.count++;
		}
		i++;
	}
	va_end(arg);
	return (flags.count);
}
