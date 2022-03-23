/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:02:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 12:13:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_position_me(char *line)
{
	int	i;
	int	pos;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			pos = i;
		i++;
	}
	return (pos);
}

void	move_of_one_tile(t_data *data, int present, int next)
{
	if (data->line[next] == 'E' && data->flow.max == 0)
	{
		free (data->line);
		exit (1);
	}
	else if (data->line[next] == 'C')
		data->flow.count++;
	if (data->line[next] != 'E')
	{
		data->line[present] = '0';
		data->line[next] = 'P';
		data->operations++;
		ft_printf("%d\n", data->operations);
	}
	mlx_clear_window(data->mlx, data->win);
	read_map(data, &data->dim, data->line);
}

int	ft_key_hook(int keycode, t_data *data)
{
	int	me;
	int	up;
	int	down;

	me = find_position_me(data->line);
	up = me - data->dim.max_x - 1;
	down = me + data->dim.max_x + 1;
	if (keycode == 0 && data->line[me - 1] != '1')
		move_of_one_tile(data, me, me - 1);
	else if (keycode == 2 && data->line[me + 1] != '1')
		move_of_one_tile(data, me, me + 1);
	else if (keycode == 13 && data->line[up] != '1')
		move_of_one_tile(data, me, up);
	else if (keycode == 1 && data->line[down] != '1')
		move_of_one_tile(data, me, down);
	else if (keycode == 53)
	{
		free (data->line);
		exit (1);
	}
	return (keycode);
}
