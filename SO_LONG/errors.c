/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 12:49:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	count_horizontal(char *line)
{
	int	i;
	int	j;
	int	old;

	i = 0;
	j = 0;
	old = 0;
	while (line[old] != '\n')
		old++;
	while (line[i])
	{
		j = ft_strchrlen(line + i, '\n');
		i += j + 1;
		if (j != old)
		{
			free (line);
			ft_exit("Error\nIncorrect map\n");
		}
	}
	if (line[i] == '\0' && j != old)
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
	if (end != 1 || character != 1 || collectible < 1)
	{
		free (line);
		ft_exit("Error\nMissing elements\n");
	}
}

void	other_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
		{
			free (line);
			ft_exit("Error\nIncorrect map\n");
		}
		i++;
	}
}

int	errors(char *line)
{
	count_horizontal(line);
	check_wall(line);
	enough_elements(line);
	other_characters(line);
	return (1);
}
