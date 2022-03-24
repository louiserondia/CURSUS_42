/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/24 17:41:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	read_flow_in_file(t_data *data)
{
	int	width;
	int	height;
	
	data->flow.flow0 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow0_path, &width, &height);
	data->flow.flow1 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow1_path, &width, &height);
	data->flow.flow2 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow2_path, &width, &height);
	data->flow.flow3 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow3_path, &width, &height);
	data->flow.flow4 = mlx_xpm_file_to_image(data->mlx,
			data->flow.flow4_path, &width, &height);
}

void	read_heart_in_file(t_data *data)
{
	int	width;
	int	height;
	
	data->heart.heart1 = mlx_xpm_file_to_image(data->mlx,
			data->heart.heart1_path, &width, &height);
	data->heart.heart2 = mlx_xpm_file_to_image(data->mlx,
			data->heart.heart2_path, &width, &height);
	data->heart.heart3 = mlx_xpm_file_to_image(data->mlx,
			data->heart.heart3_path, &width, &height);
}

void	read_number_in_file(t_data *data)
{
	int	width;
	int	height;

	data->number.one = mlx_xpm_file_to_image(data->mlx,
		data->number.one_path, &width, &height);
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
			
	data->monster.chimere_left = mlx_xpm_file_to_image(data->mlx,
			data->monster.chimere_left_path, &width, &height);
	data->monster.chimere_right = mlx_xpm_file_to_image(data->mlx,
			data->monster.chimere_right_path, &width, &height);
}

void	init_sprites(t_data *data)
{
	data->img.snow_path = "sprites/big_snow_big.xpm";
	data->img.tree_path = "sprites/tree.xpm";
	data->img.brieuc_path = "sprites/brieuc.xpm";
	data->img.flower_path = "sprites/flower.xpm";
	
	data->monster.chimere_left_path = "sprites/chimere_knife_2.xpm";
	data->monster.chimere_right_path = "sprites/chimere_right.xpm";
	
	data->flow.flow0_path = "sprites/flow/me_0flow.xpm";
	data->flow.flow1_path = "sprites/flow/me_1flow.xpm";
	data->flow.flow2_path = "sprites/flow/me_2flow.xpm";
	data->flow.flow3_path = "sprites/flow/me_3flow.xpm";
	data->flow.flow4_path = "sprites/flow/me_4flow.xpm";

	data->heart.heart1_path = "sprites/heart/1heart.xpm";
	data->heart.heart2_path = "sprites/heart/2heart.xpm";
	data->heart.heart3_path = "sprites/heart/3heart.xpm";

	data->number.one_path = "sprites/number/1.xpm";
	read_in_file(data);
	read_flow_in_file(data);
	read_heart_in_file(data);
	read_number_in_file(data);
}
