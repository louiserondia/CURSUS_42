/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:38:09 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/15 20:14:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strchrl(char c, char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!strchrl(s1[i], s1, i))
			write (1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (!strchrl(s2[j], s1, i) && !strchrl(s2[j], s2, j))
			write (1, &s2[j], 1);
		j++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
}
