/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:50:18 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 19:51:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa_fd(unsigned long n, int fd, int (*f)(int))
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthexa_fd(n / 16, fd, f);
		ft_putchar_fd(f(base[n % 16]), fd);
	}
	else
		ft_putchar_fd(f(base[n]), fd);
}
