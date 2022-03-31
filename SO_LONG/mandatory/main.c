/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 17:13:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_dimensions(t_dim *dimensions, char *line)
{
	int	i;

	i = 0;
	dimensions->max_x = 0;
	dimensions->max_y = 0;
	while (line[i] && line[i] != '\n')
	{
		dimensions->max_x++;
		i++;
	}
	i = 0;
	while (line && line[i])
	{
		if (line[i] == '\n')
			dimensions->max_y++;
		i++;
	}
	if (line[i] == '\0')
		dimensions->max_y++;
	if (dimensions->max_y == dimensions->max_x)
		ft_exit (line, "Error\nIncorrect map\n");
}

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
	get_dimensions(&data.dim, data.line);
	errors(data, data.line);
	data.win = mlx_new_window(data.mlx, data.dim.max_x * 64,
			(data.dim.max_y + 1) * 64, "so_long");
	init_sprites(&data);
	read_map(&data, &data.dim, data.line);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_loop(data.mlx);
}
