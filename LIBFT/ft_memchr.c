/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:09:30 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/05 15:59:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = s;
	uc = c;
	while (*us && n > 0)
	{
		if (*us == uc)
			return ((char *)us);
		us++;
		n--;
	}
	if (c == '\0')
		return ((char *)us);
	return (0);
}
