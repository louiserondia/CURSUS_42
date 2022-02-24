/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:18:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/24 02:48:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_data *data, char **argv)
{
	int		i;
	char	**args = NULL;

	i = 0;
	args = get_all_args(argv);
	while (args[i])
		i++;
	data->argc = i;
	check_duplicate(args);
	get_into_stack(args, data);
}

char	**get_all_args(char **argv)
{
	int		i;
	char	*all_args;
	char	**args = NULL;

	i = 1;
	all_args = "";
	while (argv[i])
	{
		all_args = ft_strjoin(all_args, argv[i]);
		if (!all_args)
			ft_exit("");
		all_args = ft_strjoin(all_args, " ");
		if (!all_args)
			ft_exit("");
		i++;
	}
	args = ft_split(all_args, ' ');
	if (!args)
	{
		free (all_args);
		ft_exit("");
	}
	// free (all_args);
	 return (args);
}

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

void	get_into_stack(char **args, t_data *data)
{
	int	i;
	int	*number;
	t_list	*new;

	number = malloc(sizeof (int) * data->argc);
	if (!number)
	{
		free (args);	
		ft_exit("");
	}
	i = 0;
	while (args[i])
	{
		number[i] = ft_atoi_restrict(args[i]);
		i++;
	}
	number = transform_in_order(number, data);
	i = 0;
	while(args[i])
	{
		new = ft_lstnew(&number[i]);
		if (!new)
		{
			free (args);
			ft_exit("");
		}
		ft_lstadd_back(&data->stack_a, new);
		i++;
	}
	free (args);
	free (number);
}



int		*transform_in_order(int *tab, t_data *data)
{
	int	i;
	int	j;
	int *new_tab;

	i = 0;
	j = 0;
	new_tab = malloc(sizeof (int) * data->argc);
	if (!new_tab)
	{
		free (tab);
		ft_exit("");
	}
	while (i < data->argc)
	{
		new_tab[i] = tab[i];
		i++;
	}
	ft_sort_int_tab(tab, data->argc);
	i = 0;
	while (i < data->argc && j < data->argc)
	{
		if (new_tab[i] == tab[j])
		{
			new_tab[i] = j;
			i++;
			j = -1;
		}
		j++;
	}
	free (tab);
	return (new_tab);
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