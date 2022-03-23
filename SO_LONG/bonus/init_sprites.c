/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 18:14:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	read_me_in_file(t_data *data)
{
	int	width;
	int	height;
	
	data->flow.flow0_heart1 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow0_heart1_path, &width, &height);
	data->flow.flow0_heart2 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow0_heart2_path, &width, &height);
	data->flow.flow0_heart3 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow0_heart3_path, &width, &height);

	data->flow.flow1_heart1 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow1_heart1_path, &width, &height);
	data->flow.flow1_heart2 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow1_heart2_path, &width, &height);
	data->flow.flow1_heart3 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow1_heart3_path, &width, &height);

	data->flow.flow2_heart1 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow2_heart1_path, &width, &height);
	data->flow.flow2_heart2 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow2_heart2_path, &width, &height);
	data->flow.flow2_heart3 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow2_heart3_path, &width, &height);
	
	data->flow.flow3_heart1 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow3_heart1_path, &width, &height);
	data->flow.flow3_heart2 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow3_heart2_path, &width, &height);
	data->flow.flow3_heart3 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow3_heart3_path, &width, &height);
	
	data->flow.flow4_heart1 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow4_heart1_path, &width, &height);
	data->flow.flow4_heart2 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow4_heart2_path, &width, &height);
	data->flow.flow4_heart3 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow4_heart3_path, &width, &height);
}

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
	data->img.chimere = mlx_xpm_file_to_image(data->mlx,
			data->img.chimere_path, &width, &height);
}

void	init_sprites(t_data *data)
{
	data->img.snow_path = "sprites/big_snow_big.xpm";
	data->img.tree_path = "sprites/tree_2_big.xpm";
	data->img.brieuc_path = "sprites/brieuc.xpm";
	data->img.flower_path = "sprites/flower_3.xpm";
	data->img.me_path = "sprites/me_small.xpm";
	data->img.chimere_path = "sprites/chimere_knife_2.xpm";
	data->flow.flow0_heart1_path = "sprites/flow_heart/0flow_1heart.xpm";
	data->flow.flow0_heart2_path = "sprites/flow_heart/0flow_2heart.xpm";
	data->flow.flow0_heart3_path = "sprites/flow_heart/0flow_3heart.xpm";
	data->flow.flow1_heart1_path = "sprites/flow_heart/1flow_1heart.xpm";
	data->flow.flow1_heart2_path = "sprites/flow_heart/1flow_2heart.xpm";
	data->flow.flow1_heart3_path = "sprites/flow_heart/1flow_3heart.xpm";
	data->flow.flow2_heart1_path = "sprites/flow_heart/2flow_1heart.xpm";
	data->flow.flow2_heart2_path = "sprites/flow_heart/2flow_2heart.xpm";
	data->flow.flow2_heart3_path = "sprites/flow_heart/2flow_3heart.xpm";
	data->flow.flow3_heart1_path = "sprites/flow_heart/3flow_1heart.xpm";
	data->flow.flow3_heart2_path = "sprites/flow_heart/3flow_2heart.xpm";
	data->flow.flow3_heart3_path = "sprites/flow_heart/3flow_3heart.xpm";
	data->flow.flow4_heart1_path = "sprites/flow_heart/4flow_1heart.xpm";
	data->flow.flow4_heart2_path = "sprites/flow_heart/4flow_2heart.xpm";
	data->flow.flow4_heart3_path = "sprites/flow_heart/4flow_3heart.xpm";
	read_in_file(data);
	read_me_in_file(data);
}
