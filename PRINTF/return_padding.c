/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:24:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/25 19:14:45 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_padding(char c, t_flags *flags, va_list copy)
{
	int		padding;

	padding = 0;
	if (flags->is_plus || flags->is_space)
		padding++;
	if (flags->is_sharp)
		padding += 2;
	if (c == 'c' || c == '%')
		padding += 1;
	else if (c == 's')
		padding = return_padding_str(flags, copy);
	else if (c == 'd')
		padding += ft_nbrlen(va_arg(copy, int));
	else if (c == 'u')
		padding += ft_nbrlen(va_arg(copy, unsigned int));
	else if (c == 'x')
		padding += ft_hexalen(va_arg(copy, unsigned int));
	else if (c == 'p')
		padding += ft_hexalen(va_arg(copy, unsigned long)) + 2;
	if ((c == 'd' || c == 'u' || c == 'x' || c == 'p') && flags->precision > padding)
		padding = flags->precision;
	return (padding);
}

int	return_padding_str(t_flags *flags, va_list copy)
{
	char	*value;

	value = va_arg(copy, char *);
	if (!value)
		return (ft_strlen("(null)"));
	else if (ft_strlen(value) > (size_t)flags->precision)
		return (flags->precision);
	else
		return (ft_strlen(value));
}
