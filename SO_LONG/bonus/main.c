/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 12:13:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	ft_memset(&data, 0, sizeof (t_data));
	data.mlx = mlx_init();
	data.line = get_map_in_line(argv[1]);
	data.heart.count_me = 3;
	data.heart.count_monster = 3;
	get_dimensions(&data.dim, data.line);
	errors(data, data.line);
	data.win = mlx_new_window(data.mlx, data.dim.max_x * 64,
			(data.dim.max_y + 1) * 64, "so_long");
	init_sprites(&data);
	read_map(&data, &data.dim, data.line);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_loop_hook(data.mlx, animate_gun, &data);
	mlx_loop(data.mlx);
}
