/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:06:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 12:15:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_tab(t_data *data, void **tab)
{
	tab[0] = data->img.snow;
	tab[1] = data->img.tree;
	tab[2] = data->img.brieuc;
	tab[3] = data->img.flower;
	tab[4] = data->img.me;
	tab[5] = data->flow.me_1flower;
	tab[6] = data->flow.me_2flower;
	tab[7] = data->flow.me_3flower;
	tab[8] = data->flow.me_4flower;
}

void	ft_destroy_all(t_data *data)
{
	int		i;
	void	*tab[9];

	i = 0;
	create_tab(data, tab);
	if (data->line)
		free (data->line);
	while (i < 9)
	{
		mlx_destroy_image(data->mlx, tab[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	free (data->mlx);
	exit (1);
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
