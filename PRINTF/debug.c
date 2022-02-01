/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:10:46 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/22 12:21:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	debug(t_flags *flags)
{
	printf("\n\nsharp = %d\n", flags->is_sharp);
	printf("plus = %d\n", flags->is_plus);
	printf("space = %d\n", flags->is_space);
	printf("minus = %d\n", flags->is_minus);
	printf("zero = %d\n", flags->is_zero);
	printf("precision = %d\n", flags->precision);
	printf("width = %d\n", flags->width);
	printf("count = %d\n", flags->count);
}
