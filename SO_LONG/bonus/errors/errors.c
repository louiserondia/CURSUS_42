/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 14:12:03 by lrondia          ###   ########.fr       */
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
	{
		ft_printf("Error\nWrong file name\n");
		exit(EXIT_FAILURE);
	}
}

void	count_horizontal(int max, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line && line[i])
	{
		j = 0;
		while (line && line[i] && line[i] != '\n')
		{
			i++;
			j++;
		}
		if (line[i] == '\n' && j != max)
			ft_exit(line, "Error\nIncorrect map\n");
		else if (line[i] == '\n' && j == max)
			i++;
	}
	if (line[i] == '\0' && (j != max || line[i - 1] == '\n'))
		ft_exit(line, "Error\nIncorrect map\n");
}

void	enough_elements(char *line)
{
	int	i;
	int	end;
	int	character;
	int	collectible;
	int	monster;

	i = 0;
	end = 0;
	character = 0;
	collectible = 0;
	monster = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			end++;
		else if (line[i] == 'P')
			character++;
		else if (line[i] == 'C')
			collectible++;
		else if (line[i] == 'M')
			monster++;
		i++;
	}
	if (end < 1 || character != 1 || collectible < 1 || monster > 1)
		ft_exit(line, "Error\nWrong amount of elements\n");
}

void	other_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C' && line[i] != 'M'
			&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
			ft_exit(line, "Error\nIncorrect map\n");
		i++;
	}
}

void	errors(t_data data, char *line)
{
	count_horizontal(data.dim.max_x, line);
	check_wall(line);
	enough_elements(line);
	other_characters(line);
}
