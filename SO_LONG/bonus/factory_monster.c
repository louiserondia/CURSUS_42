/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_monster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:22:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/24 17:16:11 by lrondia          ###   ########.fr       */
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

void	set_monster_left(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->monster.chimere_left,
		dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_monster);
}

void	set_monster_right(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->monster.chimere_right,
		dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_monster);
}
