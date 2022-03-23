/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 12:16:48 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_in_file(t_data *data)
{
	int	width;
	int	height;

	data->img.snow = mlx_xpm_file_to_image(data->mlx,
			data->img.snow_path, &width, &height);
	data->img.tree = mlx_xpm_file_to_image(data->mlx,
			data->img.tree_path, &width, &height);
	data->img.brieuc = mlx_xpm_file_to_image(data->mlx,
			data->img.brieuc_path, &width, &height);
	data->img.flower = mlx_xpm_file_to_image(data->mlx,
			data->img.flower_path, &width, &height);
	data->img.me = mlx_xpm_file_to_image(data->mlx,
			data->img.me_path, &width, &height);
	data->flow.me_1flower = mlx_xpm_file_to_image(data->mlx,
			data->flow.me_1flower_path, &width, &height);
	data->flow.me_2flower = mlx_xpm_file_to_image(data->mlx,
			data->flow.me_2flower_path, &width, &height);
	data->flow.me_3flower = mlx_xpm_file_to_image(data->mlx,
			data->flow.me_3flower_path, &width, &height);
	data->flow.me_4flower = mlx_xpm_file_to_image(data->mlx,
			data->flow.me_4flower_path, &width, &height);
}

void	init_sprites(t_data *data)
{
	data->img.snow_path = "sprites/big_snow_big.xpm";
	data->img.tree_path = "sprites/tree_2_big.xpm";
	data->img.brieuc_path = "sprites/brieuc.xpm";
	data->img.flower_path = "sprites/flower_3.xpm";
	data->img.me_path = "sprites/me_small.xpm";
	data->flow.me_1flower_path = "sprites/me_1flow.xpm";
	data->flow.me_2flower_path = "sprites/me_2flow.xpm";
	data->flow.me_3flower_path = "sprites/me_3flow.xpm";
	data->flow.me_4flower_path = "sprites/me_4flow.xpm";
	read_in_file(data);
}
