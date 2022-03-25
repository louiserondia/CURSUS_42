/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:19:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/25 15:14:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_table(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->number.table,
		64, 32);
}

void	create_tab(t_data *data, void **tab)
{
	tab[0] = data->number.zero;
	tab[1] = data->number.one;
	tab[2] = data->number.two;
	tab[3] = data->number.three;
	tab[4] = data->number.four;
	tab[5] = data->number.five;
	tab[6] = data->number.six;
	tab[7] = data->number.seven;
	tab[8] = data->number.eight;
	tab[9] = data->number.nine;
}

void	set_number(t_data *data, int i, int x)
{
	void	*tab[10];

	create_tab(data, tab);
	if (i >= 10)
	{
		set_number(data, i / 10, x - 16);
		set_number(data, i % 10, x);
	}
	if (i < 10)
		mlx_put_image_to_window(data->mlx, data->win, tab[i],
		x, 32);
}
