/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 15:29:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char c, t_flags *flags, va_list arg)
{
	check_sharp(c, flags);
	check_plus(c, flags, arg);
	check_space(c, flags, arg);
	check_wildcard(c, flags, arg);
}

void	check_sharp(char c, t_flags *flags)
{
	if (c == 'x' && flags->is_sharp)
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

void	check_wildcard(char c, t_flags *flags, va_list arg)
{
	int		i;
	int		len;
	int		width;
	va_list	copy;

	if (!flags->is_wildcard)
		return ;
	i = 0;
	len = 0;
	width = va_arg(arg, int);
	va_copy(copy, arg);
	if (c == 'c' || c == '%')
		len = 1;
	else if (c == 's')
		len = ft_strlen(va_arg(copy, char *));
	else if (c == 'd' || c == 'u')
		len = ft_nbrlen(va_arg(copy, int));
	else if (c == 'x' || c == 'p')
		len = ft_hexalen(va_arg(copy, int));
	while (i < width - len)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	flags->count += width - len;
}
