/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:02:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/22 20:51:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_of_one_tile(t_data *data, int present, int next)
{
	ft_printf("%d\n", data->operations);
	data->operations++;
	if (data->line[next] == 'E' && data->flow.max == 0)
		exit (1);
	else if (data->line[next] == 'C')
		data->flow.count++;
	if (data->line[next] != 'E')
	{
		data->line[present] = '0';
		data->line[next] = 'P';
	}
	mlx_clear_window(data->mlx, data->win);
	read_map(data, &data->dim, data->line);
}

int	ft_key_hook(int keycode, t_data *data)
{
	int	i;
	int	up;
	int	down;

	i = data->dim.pos_me;
	up = i - data->dim.max_x - 1;
	down = i + data->dim.max_x + 1;
	if (keycode == 0 && data->line[i - 1] != '1')
		move_of_one_tile(data, i, i - 1);
	else if (keycode == 2 && data->line[i + 1] != '1')
		move_of_one_tile(data, i, i + 1);
	else if (keycode == 13 && data->line[up] != '1')
		move_of_one_tile(data, i, up);
	else if (keycode == 1 && data->line[down] != '1')
		move_of_one_tile(data, i, down);
	return (keycode);
}
