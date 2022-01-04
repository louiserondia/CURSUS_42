/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:03:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/04 16:11:31 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*usrc;
	unsigned char		*udst;

	i = 0;
	usrc = src;
	udst = dst;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}
