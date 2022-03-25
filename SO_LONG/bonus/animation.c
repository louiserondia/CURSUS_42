/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:33:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/25 19:24:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	get_coordinates(t_data *data)
{
	int	i;

	i = find_position(data->line, 'P');
	data->dim.x = i % data->dim.max_x - 1;
	data->dim.x *= 64;
	data->dim.y = i / data->dim.max_x;
	data->dim.y *= 64;
}

int	animate_gun(t_data *data)
{
	get_coordinates(data);
	if (data->gun.time >= 1)
	{
		data->gun.time++;
		if (data->gun.time < 10)
		{
			ft_printf("%d\n", data->gun.time);
			data->gun.gun_nb = 6;
			mlx_clear_window(data->mlx, data->win);
			read_map(data, &data->dim, data->line);
		}
		else if (data->gun.time < 20)
		{
			ft_printf("ok2\n");
			data->gun.gun_nb = 5;
			mlx_clear_window(data->mlx, data->win);
			read_map(data, &data->dim, data->line);
		}
		else if (data->gun.time > 20000)
		{
			data->gun.time = 0;
			data->gun.gun_nb = 0;
			mlx_clear_window(data->mlx, data->win);
			read_map(data, &data->dim, data->line);
		}	
		// while (data->gun.time < 100000)
		// {
		// 	mlx_put_image_to_window(data->mlx, data->win, data->gun.gun5,
		// 		data->dim.x, data->dim.y);
		// 	data->gun.time++;
		// }
		return (1);
	}
	else
		return (0);
}
