/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:15:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/04 17:40:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;
	int		index;

	cc = c;
	i = 0;
	index = -1;
	while (s[i])
	{
		if (s[i] == c)
			index = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (index != -1)
		return ((char *)s + index);
	return (0);
}
