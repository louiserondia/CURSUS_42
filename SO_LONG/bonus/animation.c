/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:33:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/30 16:16:39 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_coordinates(t_data *data)
{
	int	i;

	i = find_position(data->line, 'P');
	data->dim.x = i % data->dim.max_x - 1;
	data->dim.x *= 64;
	data->dim.y = i / data->dim.max_x;
	data->dim.y *= 64;
}

void	attack_gun(t_data *data)
{
	int	monster;
	int	me;
	int	y;

	monster = find_position(data->line, 'M');
	me = find_position(data->line, 'P');
	y = me / (data->dim.max_x + 1);
	if (data->gun.time == 0)
		return ;
	if (data->flow.orientation == 0 && monster < me
		&& monster > (data->dim.max_x * y))
		data->heart.count_monster--;
	else if (data->flow.orientation == 1 && monster > me
		&& monster < (data->dim.max_x + 1) * (y + 1))
		data->heart.count_monster--;
}

int	animate_gun(t_data *data)
{
	get_coordinates(data);
	if (data->gun.time >= 1)
	{
		data->gun.time++;
		if (data->gun.time < 14)
			data->gun.gun_nb = 6 - (data->gun.time / 2);
		else if (data->gun.time > 24 && data->gun.time < 36)
			data->gun.gun_nb = (data->gun.time / 2) - 12;
		if (data->gun.time == 20)
			attack_gun(data);
		else if (data->gun.time > 36)
		{
			data->gun.time = 0;
			data->gun.gun_nb = 0;
		}
		mlx_clear_window(data->mlx, data->win);
		read_map(data, &data->dim, data->line);
	}
	return (0);
}
