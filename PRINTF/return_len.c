/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:24:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/22 13:57:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_len(char c, t_flags *flags, va_list arg)
{
	int	len;
	va_list	copy;

	va_copy(copy, arg);
	len = 0;
	if (flags->is_plus || flags->is_space)
		len++;
	if (flags->is_sharp)
		len += 2;
	if (c == 'c' || c == '%')
		len += 1;
	else if (c == 's')
		len += ft_strlen(va_arg(copy, char *));
	else if (c == 'd')
		len += ft_nbrlen(va_arg(copy, int));
	else if (c == 'u')
		len += ft_nbrlen(va_arg(copy, unsigned int));
	if ((c == 'd' || c == 'u') && flags->precision > len)
		len = flags->precision;
	else if (c == 'x' || c == 'p')
		len += ft_hexalen(va_arg(copy, unsigned long));
	// if (c == 'd' && )
	return (len);
}
