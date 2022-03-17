/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:22:15 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/16 17:35:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (same_str(args[i], args[j]))
			{
				free (args);
				ft_exit("Error\n");
			}
			j++;
		}	
		i++;
	}
}

void	copy_tab(int *tab, int *new_tab, int nb_arg)
{
	int	i;

	i = 0;
	while (i < nb_arg)
	{
		new_tab[i] = tab[i];
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)

{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void	create_new_list(t_data *data, char **args)
{
	int		i;
	t_list	*new;

	i = 0;
	while (args[i])
	{
		new = ft_lstnew(&data->number[i]);
		if (!new)
		{
			free (args);
			ft_exit("");
		}
		ft_lstadd_back(&data->stack_a, new);
		i++;
	}
}

int	is_sorted(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (*(int *)lst->content != i)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}
