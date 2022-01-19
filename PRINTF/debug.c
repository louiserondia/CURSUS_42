/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:10:46 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 16:54:28 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	debug(t_flags *flags)
{
	ft_printf("sharp = %d\n", flags->is_sharp);
	ft_printf("plus = %d\n", flags->is_plus);
	ft_printf("space = %d\n", flags->is_space);
	ft_printf("minus = %d\n", flags->is_minus);
	ft_printf("zero = %d\n", flags->is_zero);
	ft_printf("dot = %d\n", flags->is_dot);
	ft_printf("width = %d\n", flags->width);
	ft_printf("count = %d\n", flags->count);
}
