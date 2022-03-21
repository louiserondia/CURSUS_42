/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/21 20:28:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_obstacle(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->tree, dimensions->x, dimensions->y);
}

void	set_character(t_data *data, t_dim *dimensions)
{
	mlx_put_image_to_window(data->mlx, data->win, data->me, dimensions->x, dimensions->y);
}

char	*get_map_in_line(void)
{
	int		fd;
	char	*line;
	char	*buffer;
	
	fd = open("map.ber", O_RDONLY);
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
	while (line[i] && line[i + 1] != '\n')
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
	
	data->snow_path = "sprites/big_snow_big.xpm";
	data->tree_path = "sprites/tree_2_big.xpm";
	data->wood_path = "sprites/wood_2_big.xpm";
	data->me_path = "sprites/me_small.xpm";
	data->snow = mlx_xpm_file_to_image(data->mlx, data->snow_path, &width, &height);
	data->tree = mlx_xpm_file_to_image(data->mlx, data->tree_path, &width, &height);
	data->wood = mlx_xpm_file_to_image(data->mlx, data->wood_path, &width, &height);
	data->me =  mlx_xpm_file_to_image(data->mlx, data->me_path, &width, &height);
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
			mlx_put_image_to_window(data->mlx, data->win, data->snow, x * 64, y * 64);
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
	while (line && line[i])
	{
		if (line[i] == '1')
			set_obstacle(data, dimensions);
		else if (line[i] == 'P')
			set_character(data, dimensions);
		dimensions->x += 64;
		if (line[i] == '\n')
		{
			dimensions->x = 0;
			dimensions->y += 64;
		}
		i++;
	}
}

int	main(void)
{
	char	*line;
	t_data	data;
	t_dim	dimensions;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1024, 1024, "louise_map");
	line = get_map_in_line();
	get_dimensions(&dimensions, line);
	init_sprites(&data);
	init_map(&data, &dimensions);
	read_map(&data, &dimensions, line);
	mlx_key_hook(data.win, ft_key_hook, &data);	
	mlx_loop(data.mlx);
	// free (line);
}
