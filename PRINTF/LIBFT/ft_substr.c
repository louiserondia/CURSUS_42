/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:00:34 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/11 12:08:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		ptr = malloc(sizeof(s[0]) * (ft_strlen(s) + 1));
	else
		ptr = malloc(sizeof(s[0]) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[start + i] && i < len && (start < ft_strlen(s)))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
