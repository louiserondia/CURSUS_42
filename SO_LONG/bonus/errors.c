/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/25 15:18:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	compare_horizontal(char *line, int *i, int *j, int max)
{
	*j = 0;
	while (line[*i] && line[*i] != '\n')
	{
		(*i)++;
		(*j)++;
	}
	if (line[*i] == '\n' && (*j) != max)
	{
		free (line);
		ft_exit("Error\nIncorrect map\n");
	}
	else if (line[*i] == '\n' && (*j) == max)
		(*i)++;
}

void	count_horizontal(int max, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i])
		compare_horizontal(line, &i, &j, max);
	if (line[i] == '\0' && (j != max || line[i - 1] == '\n'))
	{
		free (line);
		ft_exit("Error\nIncorrect map\n");
	}
}

void	enough_elements(char *line)
{
	int	i;
	int	end;
	int	character;
	int	collectible;

	i = 0;
	end = 0;
	character = 0;
	collectible = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			end++;
		else if (line[i] == 'P')
			character++;
		else if (line[i] == 'C')
			collectible++;
		i++;
	}
	if (end < 1 || character != 1 || collectible < 1)
	{
		free (line);
		ft_exit("Error\nWrong amount of elements\n");
	}
}

void	other_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C' && line[i] != 'M'
			&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
		{
			free (line);
			ft_exit("Error\nIncorrect map\n");
		}
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
