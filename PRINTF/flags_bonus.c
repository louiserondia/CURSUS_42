/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 12:19:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




#include <stdio.h>


void	check_flags(char c, t_flags *flags, va_list arg)
{
	check_sharp(c, flags);
	check_plus(c, flags, arg);
	check_space(c, flags, arg);
}

void	check_sharp(char c, t_flags *flags)
{
	if (c == 'x' && flags->is_sharp)
		add_prefix_address();
}

void	check_plus(char c, t_flags *flags, va_list arg)
{
	va_list	copy;
	int value;
	
	va_copy(copy, arg);
	value =  va_arg(copy, int);
	printf("value = %d\n", value);
	if (c == 'd' && flags->is_plus && value >= 0)
		ft_putchar_fd('+', 1);
}

void	check_space(char c, t_flags *flags, va_list arg)
{
	va_list	copy;
	int value;
	
	va_copy(copy, arg);
	value =  va_arg(copy, int);
	if ((c == 'd' || c == 'i') && flags->is_space && !flags->is_plus)
		ft_putchar_fd(' ', 1);
}
