/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:52:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 17:37:06 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map_in_line(char *argv)
{
	int		fd;
	char	*line;
	char	*buffer;

	check_error_name(argv);
	fd = open(argv, O_RDONLY);
	line = malloc(sizeof (char) * 1);
	if (!line)
		exit(0);
	line[0] = '\0';
	while (line)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		line = ft_strjoin(line, buffer);
		if (!line)
			exit(0);
		if (buffer)
			free (buffer);
	}	
	return (line);
}

void	init_map(t_data *data, t_dim *dimensions)
{
	int	x;
	int	y;

	y = 0;
	while (y <= dimensions->max_y)
	{
		x = 0;
		while (x < dimensions->max_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.snow, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	place_tiles(t_data *data, t_dim *dimensions, char tile)
{
	if (tile == '1')
		set_obstacle(data, dimensions);
	else if (tile == 'P')
		set_character(data, dimensions);
	else if (tile == 'C')
		set_collectible(data, dimensions);
	else if (tile == 'E')
		set_end(data, dimensions);
}

void	count_flowers(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			data->flow.max++;
		i++;
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
	count_flowers(data, data->line);
	while (line[i])
	{
		place_tiles(data, dimensions, line[i]);
		dimensions->x += 64;
		if (line[i] == '\n')
		{
			dimensions->x = 0;
			dimensions->y += 64;
		}
		i++;
	}
}
