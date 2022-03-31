/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 18:21:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_obstacle(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.tree,
		dimensions->x, dimensions->y);
}

void	set_character(t_data *data, t_dim *dim)
{
	if (data->flow.count == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.me,
			dim->x, dim->y);
	else if (data->flow.count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.me_1flower,
			dim->x, dim->y);
	else if (data->flow.count == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.me_2flower,
			dim->x, dim->y);
	else if (data->flow.count == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.me_3flower,
			dim->x, dim->y);
	else if (data->flow.count >= 4)
		mlx_put_image_to_window(data->mlx, data->win, data->flow.me_4flower,
			dim->x, dim->y);
}

void	set_end(t_data *data, t_dim *dimensions)
{
	if (data->flow.max == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.brieuc_happy,
			dimensions->x, dimensions->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.brieuc,
			dimensions->x, dimensions->y);
}

void	set_collectible(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.flower,
		dimensions->x + 24, dimensions->y + 32);
}
