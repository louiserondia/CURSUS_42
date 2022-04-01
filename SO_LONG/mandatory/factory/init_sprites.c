/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 18:50:13 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites(t_data *data)
{
	int	width;
	int	height;

	data->img.snow = mlx_xpm_file_to_image(data->mlx,
			"sprites/other/snow_new.xpm", &width, &height);
	data->img.tree = mlx_xpm_file_to_image(data->mlx,
			"sprites/other/tree.xpm", &width, &height);
	data->img.brieuc = mlx_xpm_file_to_image(data->mlx,
			"sprites/other/brieuc.xpm", &width, &height);
	data->img.brieuc_happy = mlx_xpm_file_to_image(data->mlx,
			"sprites/other/brieuc_happy.xpm", &width, &height);
	data->img.flower = mlx_xpm_file_to_image(data->mlx,
			"sprites/other/flower.xpm", &width, &height);
	data->img.me = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_0flow.xpm", &width, &height);
	data->flow.me_1flower = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_1flow.xpm", &width, &height);
	data->flow.me_2flower = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_2flow.xpm", &width, &height);
	data->flow.me_3flower = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_3flow.xpm", &width, &height);
	data->flow.me_4flower = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_4flow.xpm", &width, &height);
}
