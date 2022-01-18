/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:37:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/06 13:03:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_check_charset(s1[i], (char *)set))
		i++;
	j = i;
	if (s1[i])
	{
		while (s1[i])
			i++;
		while (ft_check_charset(s1[i - 1], (char *)set))
			i--;
	}
	k = ft_strlen(s1) - i;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) - j - k + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + j, ft_strlen(s1) - k - j + 1);
	return (ptr);
}
