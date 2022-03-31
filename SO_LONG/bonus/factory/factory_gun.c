/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:14:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 18:16:39 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	create_gun_left_tab(t_data *data, void **tab)
{
	tab[0] = data->gun.left0;
	tab[1] = data->gun.left1;
	tab[2] = data->gun.left2;
	tab[3] = data->gun.left3;
	tab[4] = data->gun.left4;
	tab[5] = data->gun.left5;
	tab[6] = data->gun.left6;
}

void	create_gun_right_tab(t_data *data, void **tab)
{
	tab[0] = data->gun.right0;
	tab[1] = data->gun.right1;
	tab[2] = data->gun.right2;
	tab[3] = data->gun.right3;
	tab[4] = data->gun.right4;
	tab[5] = data->gun.right5;
	tab[6] = data->gun.right6;
}

void	set_gun(t_data *data, t_dim *dim)
{
	int		i;
	void	*gun_left[7];
	void	*gun_right[7];

	i = data->gun.gun_nb;
	create_gun_left_tab(data, gun_left);
	create_gun_right_tab(data, gun_right);
	if (data->flow.orientation == 0)
		mlx_put_image_to_window(data->mlx, data->win, gun_left[i],
			dim->x, dim->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, gun_right[i],
			dim->x, dim->y);
}

void	set_flame(t_data *data, t_dim *dim)
{
	if (data->flow.orientation == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->gun.flame_left,
			dim->x - 64, dim->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->gun.flame_right,
			dim->x + 64, dim->y);
}
