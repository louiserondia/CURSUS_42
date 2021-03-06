/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:06:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 20:32:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(char *line, char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	if (line)
		free (line);
	exit (EXIT_FAILURE);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

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

int	find_position(char *line, char c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (line[i])
	{
		if (line[i] == c)
			pos = i;
		i++;
	}
	return (pos);
}

void	count_flowers(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			data->flow.max++;
		i++;
	}
}
