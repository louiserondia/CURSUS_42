/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:48:12 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/03 17:56:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ub;
	unsigned char	uc;

	ub = b;
	uc = c;
	i = 0;
	while (i < len)
	{
		ub[i] = uc;
		i++;
	}
	return (ub);
}
