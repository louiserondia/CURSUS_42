/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:21:57 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 12:15:22 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(char *line, char *str)
{
	if (line)
		free (line);
	while (*str)
	{
		write(2, str, 1);
		str++;
	}		
	exit (0);
}

void	obstacles_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			ft_exit(line, "Error\nIncorrect map\n");
		i++;
	}
}

void	obstacles_middle_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i - 1] && line[i - 1] != '1')
			ft_exit(line, "Error\nIncorrect map\n");
		if (line[i] == '\n' && line[i + 1] && line[i + 1] != '1')
			ft_exit(line, "Error\nIncorrect map\n");
		i++;
	}
}

void	obstacles_end_line(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i > 0 && line[i] != '\n')
	{
		if (line[i] != '1')
			ft_exit(line, "Error\nIncorrect map\n");
		i--;
	}
}

void	check_wall(char *line)
{
	obstacles_first_line(line);
	obstacles_middle_line(line);
	obstacles_end_line(line);
}
