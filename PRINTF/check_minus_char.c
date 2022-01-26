/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:04:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:04:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus_char(t_flags *flags)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	if (flags->is_minus)
		i = padding_space(len, flags->width);
	flags->count += i;
}

void	check_minus_str(t_flags *flags, char *value)
{
	int	i;
	int	len;

	i = 0;
	len = return_padding_str(flags, value);
	if (flags->is_minus)
		i = padding_space(len, flags->width);
	flags->count += i;
}

void	check_minus_percent(t_flags *flags)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	if (flags->is_minus)
		i = padding_space(len, flags->width);
	flags->count += i;
}
