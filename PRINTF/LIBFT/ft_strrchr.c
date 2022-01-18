/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:15:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/11 15:22:50 by lrondia          ###   ########.fr       */
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
		if (s[i] == cc)
			index = i;
		i++;
	}
	if (cc == '\0')
		return ((char *)s + i);
	if (index != -1)
		return ((char *)s + index);
	return (0);
}
