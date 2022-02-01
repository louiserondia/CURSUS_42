/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:07:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/27 15:48:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.is_sharp = 0;
	flags.is_plus = 0;
	flags.is_space = 0;
	flags.is_minus = 0;
	flags.is_zero = 0;
	flags.is_x_maj = 0;
	flags.is_negative = 0;
	flags.precision = -1;
	flags.width = 0;
	flags.count = 0;
	return (flags);
}

void	reset_flags(t_flags *flags)
{
	flags->is_sharp = 0;
	flags->is_plus = 0;
	flags->is_space = 0;
	flags->is_minus = 0;
	flags->is_zero = 0;
	flags->is_x_maj = 0;
	flags->is_negative = 0;
	flags->precision = -1;
	flags->width = 0;
}
