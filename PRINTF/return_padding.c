/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:24:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/24 17:54:13 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_padding(char c, t_flags *flags, va_list arg)
{
	va_list	copy;
	int		padding;

	va_copy(copy, arg);
	padding = 0;
	if (flags->is_plus || flags->is_space)
		padding++;
	if (flags->is_sharp)
		padding += 2;
	if (c == 'c' || c == '%')
		padding += 1;
	else if (c == 's')
		padding += ft_strlen(va_arg(copy, char *));
	else if (c == 'd')
		padding += ft_nbrlen(va_arg(copy, int));
	else if (c == 'u')
		padding += ft_nbrlen(va_arg(copy, unsigned int));
	else if (c == 'p')
		padding += ft_strlen("ffffffffffff");
	else if (c == 'x')
		padding += ft_hexalen(va_arg(copy, unsigned int));
	if ((c == 'd' || c == 'u' || c == 'x' || c == 'p') && flags->precision > padding)
		padding = flags->precision;
	return (padding);
}
