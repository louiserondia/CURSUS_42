/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 20:32:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit(NULL, "Error\nWrong number of arguments\n");
	ft_memset(&data, 0, sizeof (t_data));
	data.line = get_map_in_line(argv[1]);
	get_dimensions(&data.dim, data.line);
	errors(data, data.line);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_exit(data.line, "Error\n");
	data.win = mlx_new_window(data.mlx, data.dim.max_x * 64,
			(data.dim.max_y + 1) * 64, "so_long");
	if (!data.win)
	{
		free (data.mlx);
		ft_exit(data.line, "Error\n");
	}
	init_sprites(&data);
	read_map(&data, &data.dim, data.line);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_destroy_all, &data);
	mlx_loop(data.mlx);
}
