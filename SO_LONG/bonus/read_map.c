/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:52:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 18:12:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_error_name(char *argv)
{
	int		i;
	int		j;
	char	end[5];

	i = ft_strlen(argv) - 1;
	j = 0;
	while (j < 4 && i > 0)
	{
		end[j] = argv[i];
		i--;
		j++;
	}
	end[j] = '\0';
	if (!ft_strcmp(end, "reb."))
		ft_exit("Error\nWrong file name\n");
}

char	*get_map_in_line(char *argv)
{
	int		fd;
	char	*line;
	char	*buffer;

	check_error_name(argv);
	fd = open(argv, O_RDONLY);
	line = malloc(sizeof (char) * 1);
	if (!line)
		ft_exit("Error\n");
	line[0] = '\0';
	while (line)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		line = ft_strjoin(line, buffer);
		if (!line)
			ft_exit("Error\n");
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
	while (y < dimensions->max_y)
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
	{
		data->flow.max++;
		set_collectible(data, dimensions);
	}
	else if (tile == 'E')
		set_end(data, dimensions);
	else if (tile == 'M')
		set_monster(data, dimensions);
		
}

void	read_map(t_data *data, t_dim *dimensions, char *line)
{
	int	i;

	i = 0;
	dimensions->x = 0;
	dimensions->y = 0;
	data->flow.max = 0;
	if (data->flow.heart_count == 0)
	{
		free (data->line);
		exit (1);
	}
	init_map(data, dimensions);
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
