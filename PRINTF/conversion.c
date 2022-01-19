/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:50 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 17:27:12 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_char(va_list arg, t_flags *flags)
{
	ft_putchar_fd(va_arg(arg, int), 1);
	flags->count++;
}

void	conversion_str(va_list arg, t_flags *flags)
{
	char	*value;

	check_flags('s', flags, arg);
	value = va_arg(arg, char *);
	if (!value)
	{
		ft_putstr_fd("(null)", 1);
		flags->count += 6;
	}
	else
	{
		flags->count += ft_strlen(value);
		ft_putstr_fd(value, 1);
	}
}

void	conversion_int(va_list arg, t_flags *flags)
{
	int	value;

	check_flags('d', flags, arg);
	value = va_arg(arg, int);
	ft_putnbr_fd(value, 1);
	flags->count += ft_nbrlen(value);
}

void	conversion_unsigned(va_list arg, t_flags *flags)
{
	int	value;

	value = va_arg(arg, unsigned int);
	ft_putunsigned_fd(value, 1);
	flags->count += ft_nbrlen(value);
}

void	conversion_ptr(va_list arg, t_flags *flags)
{
	unsigned long	value;

	value = va_arg(arg, unsigned long);
	add_prefix_address(flags);
	ft_puthexa_fd(value, 1, ft_tolower);
	flags->count += ft_strlen("0xffffffffffff");
}

void	conversion_hex(va_list arg, int (*f)(int), t_flags *flags)
{
	unsigned int	value;

	check_flags('x', flags, arg);
	value = va_arg(arg, unsigned int);
	ft_puthexa_fd(value, 1, f);
	flags->count += ft_hexalen(value);
}

void	conversion_percent(t_flags *flags)
{
	ft_putchar_fd('%', 1);
	flags->count++;
}
