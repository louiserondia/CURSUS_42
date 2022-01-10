/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:02:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/10 14:23:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*copy;

	i = 0;
	if (!s || !f)
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	while (s[i])
	{	
		copy[i] = f(i, s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
