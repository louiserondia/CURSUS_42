/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/22 20:44:31 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map_in_line(char *argv)
{
	int		fd;
	char	*line;
	char	*buffer;
	
	// error_name(argv);
	fd = open(argv, O_RDONLY);
	line = malloc(1);
	line[0] = '\0';
	while (line)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (buffer)
			free (buffer);
	}
	return (line);
}

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
}

void	init_sprites(t_data *data)
{
	int	width;
	int	height;
	
	data->img.snow_path = "sprites/big_snow_big.xpm";
	data->img.tree_path = "sprites/tree_2_big.xpm";
	data->img.wood_path = "sprites/brieuc.xpm";
	data->img.flower_path = "sprites/flower_3.xpm";
	data->img.me_path = "sprites/me_small.xpm";
	data->flow.me_1flower_path = "sprites/me_1flow.xpm";
	data->flow.me_2flower_path = "sprites/me_2flow.xpm";
	data->flow.me_3flower_path = "sprites/me_3flow.xpm";
	data->flow.me_4flower_path = "sprites/me_4flow.xpm";
	data->img.snow = mlx_xpm_file_to_image(data->mlx, data->img.snow_path, &width, &height);
	data->img.tree = mlx_xpm_file_to_image(data->mlx, data->img.tree_path, &width, &height);
	data->img.wood = mlx_xpm_file_to_image(data->mlx, data->img.wood_path, &width, &height);
	data->img.flower =  mlx_xpm_file_to_image(data->mlx, data->img.flower_path, &width, &height);
	data->img.me =  mlx_xpm_file_to_image(data->mlx, data->img.me_path, &width, &height);
	data->flow.me_1flower =  mlx_xpm_file_to_image(data->mlx, data->flow.me_1flower_path, &width, &height);
	data->flow.me_2flower =  mlx_xpm_file_to_image(data->mlx, data->flow.me_2flower_path, &width, &height);
	data->flow.me_3flower =  mlx_xpm_file_to_image(data->mlx, data->flow.me_3flower_path, &width, &height);
	data->flow.me_4flower =  mlx_xpm_file_to_image(data->mlx, data->flow.me_4flower_path, &width, &height);
}

void	init_map(t_data *data, t_dim *dimensions)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < dimensions->max_y)
	{
		x = 0;
		while (x < dimensions->max_x)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img.snow, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	read_map(t_data *data, t_dim *dimensions, char *line)
{
	int	i;

	i = 0;
	dimensions->x = 0;
	dimensions->y = 0;
	data->flow.max = 0;
	init_map(data, dimensions);
	while (line && line[i])
	{
		if (line[i] == '1')
			set_obstacle(data, dimensions);
		else if (line[i] == 'P')
		{
			set_character(data, dimensions);
			dimensions->pos_me = i;
		}
		else if (line[i] == 'C')
		{
			data->flow.max++;
			set_collectible(data, dimensions);
		}
		else if (line[i] == 'E')
			set_end(data, dimensions);
		dimensions->x += 64;
		if (line[i] == '\n')
		{
			dimensions->x = 0;
			dimensions->y += 64;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit("Error\n");
	ft_memset(&data, 0, sizeof (t_data));
	data.mlx = mlx_init();
	data.line = get_map_in_line(argv[1]);
	errors(data.line);
	data.flow.count = 0;
	data.operations = 0;
	get_dimensions(&data.dim, data.line);
	data.win = mlx_new_window(data.mlx, data.dim.max_x * 64, (data.dim.max_y + 1) * 64, "so_long");
	init_sprites(&data);
	read_map(&data, &data.dim, data.line);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_loop(data.mlx);
	// free (data.line);
}
