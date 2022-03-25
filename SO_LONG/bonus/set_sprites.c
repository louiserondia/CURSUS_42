/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/25 19:01:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_obstacle(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.tree,
		dim->x, dim->y);
}

void	set_character(t_data *data, t_dim *dim)
{
	if (data->gun.time > 0)
	{
		set_gun(data, dim);
		return ;
	}
	if (data->flow.count == 0)
		set_character_0flow(data, dim);
	else if (data->flow.count == 1)
		set_character_1flow(data, dim);
	else if (data->flow.count == 2)
		set_character_2flow(data, dim);
	else if (data->flow.count == 3)
		set_character_3flow(data, dim);
	else if (data->flow.count >= 4)
		set_character_4flow(data, dim);
}

void	set_end(t_data *data, t_dim *dim)
{
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
	if (data->monster.left == 1)
		set_monster_left(data, dim);
	else if (data->monster.right == 1)
		set_monster_right(data, dim);
}
