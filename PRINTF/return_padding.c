/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:24:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 18:29:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_padding_str(t_flags *flags, char *value)
{
	if (!value)
		return (ft_strlen("(null)"));
	else if (ft_strlen(value) > (size_t)flags->precision)
		return (flags->precision);
	else
		return (ft_strlen(value));
}

int	return_padding_int(t_flags *flags, long value)
{
	int	padding;

	padding = 0;
	if (flags->is_plus || flags->is_space)
		padding++;
	if (ft_nbrlen(value) < flags->precision)
		return (flags->precision);
	else
		padding += ft_nbrlen(value);
	return (padding);
}

int	return_padding_unsigned(t_flags *flags, unsigned int value)
{
	if (ft_unsignedlen(value) < flags->precision)
		return (flags->precision);
	else
		return (ft_unsignedlen(value));
}

int	return_padding_hex(t_flags *flags, unsigned int value)
{
	int	padding;

	padding = 0;
	if (flags->is_sharp)
		padding += 2;
	if (ft_hexalen(value) < flags->precision)
		padding = flags->precision;
	else
		padding += ft_hexalen(value);
	return (padding);
}

int	return_padding_ptr(t_flags *flags, unsigned long value)
{
	if (ft_hexalen(value) < flags->precision)
		return (flags->precision);
	else
		return (ft_hexalen(value) + 2);
}
