/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:18:00 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/24 17:12:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_character_0flow(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0,
				dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_me);
}

void	set_character_1flow(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1,
			dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_me);
}

void	set_character_2flow(t_data *data, t_dim *dim)
{	
	mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2,
		dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_me);
}
void	set_character_3flow(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3,
			dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_me);
}

void	set_character_4flow(t_data *data, t_dim *dim)
{
	mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4,
			dim->x, dim->y);
	set_hearts(data, dim, data->heart.count_me);
}