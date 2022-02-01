/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:49:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/27 15:48:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_prefix_address(t_flags *flags)
{
	if (!flags->is_x_maj)
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0X", 1);
	flags->count += 2;
}

void	print_sign(t_flags *flags, long *value)
{
	if (*value < 0)
	{
		ft_putchar_fd('-', 1);
		*value *= -1;
	}
	flags->count++;
}

int	padding_zero(int padding, int max)
{
	int	i;

	i = 0;
	while (padding < max)
	{
		ft_putchar_fd('0', 1);
		padding++;
		i++;
	}
	return (i);
}

int	padding_space(int padding, int max)
{
	int	i;

	i = 0;
	while (padding < max)
	{
		ft_putchar_fd(' ', 1);
		padding++;
		i++;
	}
	return (i);
}
