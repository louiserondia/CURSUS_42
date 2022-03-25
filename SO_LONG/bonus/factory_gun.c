/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:14:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/25 19:20:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	create_gun_tab(t_data *data, void **tab)
{
	tab[0] = data->gun.gun1;
	tab[1] = data->gun.gun2;
	tab[2] = data->gun.gun3;
	tab[3] = data->gun.gun4;
	tab[4] = data->gun.gun5;
	tab[5] = data->gun.gun6;
	tab[6] = data->gun.gun7;
}

void	set_gun(t_data *data, t_dim *dim)
{
	int		i;
	void	*gun[7];

	i = data->gun.gun_nb;
	create_gun_tab(data, gun);
	mlx_put_image_to_window(data->mlx, data->win, gun[i],
				dim->x, dim->y);
}