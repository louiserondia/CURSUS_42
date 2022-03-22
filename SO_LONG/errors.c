/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/22 20:18:46 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_name(char *argv)
{
	int		i;
	int		j;
	char	end[4];

	i = ft_strlen(argv) - 1;
	j = 0;
	while (j < 4 && i > 0)
	{
		end[j] = argv[i];
		i--;
		j++;
	}
	if (!ft_strcmp(end, ".ber"))
		ft_exit("Error\n");
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
		if (line[i] == '\n')
		{
			if (j != old)
				ft_exit("Error\n");
			j = 0;
			i++;
		}
		i++;
		j++;
	}
	if (line[i] == '\0')
	{
		if (j != old)
			ft_exit("Error\n");
	}
}

void	first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			ft_exit("Error\n");
		i++;
	}
}

void	middle_end_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i - 1] && line[i - 1] != '1')
			ft_exit("Error\n");
		if (line[i] == '\n' && line[i + 1] && line[i + 1] != '1')
			ft_exit("Error\n");
		i++;
	}
	i--;
	while (i > 0 && line[i] != '\n')
	{
		if (line[i] != '1')
			ft_exit("Error\n");
		i--;
	}
}

int	errors(char *line)
{
	count_horizontal(line);
	first_line(line);
	middle_end_line(line);
	return (1);
}
