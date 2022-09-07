/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:45:34 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/07 18:40:56 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int	create_tab(t_tab *tab)
{
	int	i;
	
	i = 0;
	tab->tab = malloc(sizeof (char) * (tab->size_x * tab->size_y) + 1);
	if (!tab->tab)
		return (0);
	while (i < tab->size_x * tab->size_y)
	{
	
			tab->tab[i] = tab->type;
		i++;
	}
	return (1);
}

void	create_rect(t_tab *tab)
{
	int	i;
	float	cur_x;
	float	cur_y;
	float	small;
	float	big;

	i = 0;
	while (i < tab->size_x * tab->size_y)
	{
			cur_x = i % tab->size_x;
			cur_y = i / tab->size_x;
			if (tab->content == 'r')
			{
				if (cur_x <= tab->x + tab->width && cur_x >= tab->x)
				{
					small = cur_y - tab->y;
					big = cur_y - (tab->y + tab->height);
					if (small < 1.0 && small >= 0)
						tab->tab[i] = tab->type;
					else if (big < 1.0 && big >= 0)
						tab->tab[i] = tab->type;
				}

				else if (cur_y >= tab->y && cur_y <= tab->y + tab->height)
				{
					small = cur_x - tab->x;
					big = cur_x - (tab->x + tab->width);
					if (small < 1.0 && small >= 0)
						tab->tab[i] = tab->type;
					else if (big < 1.0 && big >= 0)	
						tab->tab[i] = tab->type;
				}
			}
			else
			{
				if (cur_y <= tab->y + tab->height && cur_y >= tab->y
					&& cur_x <= tab->x + tab->width && cur_x >= tab->x)
					tab->tab[i] = tab->type;
			}
		i++;
	}
}

int	check_arg(char *argv, t_tab *tab)
{
	FILE	*file;

	file = fopen(argv, "r");
	if (!file)
		return (0);
	if (fscanf(file, "%d %d %c\n", &tab->size_x, &tab->size_y, &tab->type) != 3)
		return (0);
	if (!create_tab(tab))
		return (0);
	while (fscanf(file, "%c %f %f %f %f %c\n", &tab->content, &tab->x, &tab->y, &tab->width, &tab->height, &tab->type) == 6)
	{
		if (tab->content != 'r' && tab->content != 'R')
			return (0);
		create_rect(tab);
	}
	return (1);
}

void	print_tab(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size_x * tab->size_y)
	{
		write(1, &tab->tab[i], 1);
		if (i % tab->size_x == tab->size_x - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_tab	tab;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!check_arg(argv[1], &tab))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	print_tab(&tab);
	free(tab.tab);
}
