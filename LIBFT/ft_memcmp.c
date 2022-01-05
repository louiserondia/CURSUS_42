/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:30:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/05 16:00:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = s1;
	us2 = s2;
	while (i < n)
	{
		if (us1[i] != us2[i] && i < n)
			return ((unsigned char)us1[i] - (unsigned char)us2[i]);
		i++;
	}
	return (0);
}
