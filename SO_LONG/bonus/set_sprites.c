/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 18:21:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_obstacle(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.tree,
		dimensions->x, dimensions->y);
}

void	set_character(t_data *data, t_dim *dim)
{
	if (data->flow.flow_count == 0)
	{
		if (data->flow.heart_count == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0_heart1,
				dim->x, dim->y);
		else if (data->flow.heart_count == 2)
			mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0_heart2,
				dim->x, dim->y);
		else if (data->flow.heart_count == 3)	
			mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0_heart3,
				dim->x, dim->y);
	}
	else if (data->flow.flow_count == 1)
	{
		if (data->flow.heart_count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1_heart1,
			dim->x, dim->y);
		else if (data->flow.heart_count == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1_heart2,
			dim->x, dim->y);
		else if (data->flow.heart_count == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1_heart3,
			dim->x, dim->y);
	}
	else if (data->flow.flow_count == 2)
	{
		if (data->flow.heart_count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2_heart1,
			dim->x, dim->y);
		else if (data->flow.heart_count == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2_heart2,
			dim->x, dim->y);
		else if (data->flow.heart_count == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2_heart3,
			dim->x, dim->y);
	}
	else if (data->flow.flow_count == 3)
	{
		if (data->flow.heart_count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3_heart1,
			dim->x, dim->y);
		else if (data->flow.heart_count == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3_heart2,
			dim->x, dim->y);
		else if (data->flow.heart_count == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3_heart3,
			dim->x, dim->y);
	}
	else if (data->flow.flow_count >= 4)
	{
		if (data->flow.heart_count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4_heart1,
			dim->x, dim->y);
		else if (data->flow.heart_count == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4_heart2,
			dim->x, dim->y);
		else if (data->flow.heart_count == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4_heart3,
			dim->x, dim->y);
	}
}

void	set_end(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.brieuc,
		dimensions->x, dimensions->y);
}

void	set_collectible(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.flower,
		dimensions->x + 24, dimensions->y + 32);
}

void	set_monster(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.chimere,
		dimensions->x, dimensions->y);
}
