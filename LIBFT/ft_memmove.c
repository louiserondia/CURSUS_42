/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:33:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/04 16:30:19 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long				i;
	long				ulen;
	const unsigned char	*usrc;
	unsigned char		*udst;

	i = 0;
	ulen = len;
	usrc = src;
	udst = dst;
	if (dst - src <= 0 || dst - src >= ulen)
		ft_memcpy(dst, src, ulen);
	else
	{
		while (i < ulen)
		{
			udst[ulen - 1 - i] = usrc[ulen - 1 - i];
			i++;
		}
	}
	return (dst);
}
