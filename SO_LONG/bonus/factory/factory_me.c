/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:18:00 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 18:15:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	create_flow_tab(t_data *data, void **tab)
{
	tab[0] = data->flow.flow0;
	tab[1] = data->flow.flow1;
	tab[2] = data->flow.flow2;
	tab[3] = data->flow.flow3;
	tab[4] = data->flow.flow4;
}

void	set_character(t_data *data, t_dim *dim)
{
	int		i;
	void	*flow[5];

	if (data->gun.time > 0)
	{
		set_hearts(data, dim, data->heart.count_me);
		if (data->gun.time > 14 && data->gun.time < 20)
			set_flame(data, dim);
		set_gun(data, dim);
	}
	else
	{
		i = data->flow.count;
		create_flow_tab(data, flow);
		if (i <= 4)
			mlx_put_image_to_window(data->mlx, data->win, flow[i],
				dim->x, dim->y);
		else
			mlx_put_image_to_window(data->mlx, data->win, flow[4],
				dim->x, dim->y);
		set_hearts(data, dim, data->heart.count_me);
	}
}
