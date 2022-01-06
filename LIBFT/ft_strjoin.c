/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:29:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/06 13:29:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		i;
	int		j;
	int		count;
	char	*ptr;

	i = 0;
	j = 0;
	count = 0;
	if (!s1 || !s2)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
