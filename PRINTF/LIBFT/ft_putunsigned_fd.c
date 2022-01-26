/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:54:08 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:27:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunsigned_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
}
