/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:50 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/18 17:45:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_char(va_list arg)
{
	ft_putchar_fd(va_arg(arg, int), 1);
	return (1);
}

int	conversion_str(va_list arg)
{
	int		count;
	char	*value;

	value = va_arg(arg, char *);
	if (!value)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = ft_strlen(value);
	ft_putstr_fd(value, 1);
	return (count);
}

int	conversion_int(va_list arg)
{
	int	value;

	value = va_arg(arg, int);
	ft_putnbr_fd(value, 1);
	return (ft_nbrlen(value));
}

int	conversion_unsigned(va_list arg)
{
	int	value;

	value = va_arg(arg, unsigned int);
	ft_putunsigned_fd(value, 1);
	return (ft_nbrlen(value));
}

int	conversion_ptr(va_list arg)
{
	unsigned long	value;

	value = va_arg(arg, unsigned long);
	add_prefix_address();
	ft_puthexa_fd(value, 1, ft_tolower);
	return (ft_strlen("0xffffffffffff"));
}

int	conversion_hex(va_list arg, int (*f)(int), t_flags *flags)
{
	unsigned int	value;

	value = va_arg(arg, unsigned int);
	check_flags('x', flags);
	ft_puthexa_fd(value, 1, f);
	return (ft_hexalen(value));
}

int	conversion_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
