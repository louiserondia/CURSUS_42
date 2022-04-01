/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:04:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 20:33:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_other_tab(t_data *data, void **tab)
{
	tab[0] = data->heart.heart1;
	tab[1] = data->heart.heart2;
	tab[2] = data->heart.heart3;
	tab[3] = data->img.tree;
	tab[4] = data->img.brieuc;
	tab[5] = data->img.brieuc_happy;
	tab[6] = data->img.flower;
	tab[7] = data->monster.chimere_left;
	tab[8] = data->monster.chimere_right;
}

void	ft_destroy_img(t_data *data, int max, void **tab)
{
	int	i;

	i = 0;
	while (i < max)
	{
		mlx_destroy_image(data->mlx, tab[i]);
		i++;
	}
}

int	ft_destroy_all(t_data *data)
{
	void	*tab[10];

	if (data->line)
		free (data->line);
	create_flow_tab(data, tab);
	ft_destroy_img(data, 5, tab);
	create_number_tab(data, tab);
	ft_destroy_img(data, 10, tab);
	create_gun_left_tab(data, tab);
	ft_destroy_img(data, 7, tab);
	create_gun_right_tab(data, tab);
	ft_destroy_img(data, 7, tab);
	create_other_tab(data, tab);
	ft_destroy_img(data, 9, tab);
	mlx_destroy_window(data->mlx, data->win);
	free (data->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}
