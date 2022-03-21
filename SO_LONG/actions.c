/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:02:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/21 19:17:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	ft_printf("key : %d\n", keycode);
	if (keycode == 0)
	{
		data->x_me -= 32;
		mlx_put_image_to_window(data->mlx, data->win, data->me, data->x_me, data->y_me);
	}
	else if (keycode == 13)
	{
		data->y_me -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->me, data->x_me, data->y_me);
	}
	else if (keycode == 1)
	{
		data->y_me += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->me, data->x_me, data->y_me);
	}
	else if (keycode == 2)
	{
		data->x_me += 32;
		mlx_put_image_to_window(data->mlx, data->win, data->me, data->x_me, data->y_me);
	}
	return (keycode);
}