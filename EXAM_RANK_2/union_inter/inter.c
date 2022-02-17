/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:40:48 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/15 20:13:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchrl(char c, char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s2);
	while (s1[i])
	{
		if (ft_strchrl(s1[i], s2, len) && !ft_strchrl(s1[i], s1, i))
			write(1, &s1[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_inter(argv[1], argv[2]);
}
