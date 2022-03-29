/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/29 17:57:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_hearts(t_data *data, t_dim *dim, int count)
{
	if (count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->heart.heart1,
			dim->x, dim->y);
	else if (count == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->heart.heart2,
			dim->x, dim->y);
	else if (count == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->heart.heart3,
			dim->x, dim->y);
}

void	set_obstacle(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.tree,
		dim->x, dim->y);
}

void	set_end(t_data *data, t_dim *dim)
{
	if (data->flow.max == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.brieuc_happy,
			dim->x, dim->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.brieuc,
			dim->x, dim->y);
}

void	set_collectible(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.flower,
		dim->x + 24, dim->y + 32);
}

void	set_monster(t_data *data, t_dim *dim)
{
	if (data->monster.orientation == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->monster.chimere_left, dim->x, dim->y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->monster.chimere_right, dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_monster);
}
