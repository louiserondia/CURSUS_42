/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:18:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:23:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_data *data, char **argv)
{
	int		nb_arg;
	char	**args;

	nb_arg = 0;
	args = NULL;
	args = get_all_args(argv);
	while (args[nb_arg])
		nb_arg++;
	check_duplicate(args);
	get_into_stack(args, data, nb_arg);
}

char	**get_all_args(char **argv)
{
	int		i;
	char	*all_args;
	char	**args;

	i = 1;
	args = NULL;
	all_args = ft_calloc(1, sizeof (char));
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
		ft_exit("");
	if (all_args)
		free (all_args);
	return (args);
}

void	get_into_stack(char **args, t_data *data, int nb_arg)
{
	int	i;

	i = 0;
	data->number = malloc(sizeof (int) * nb_arg);
	if (!data->number)
	{
		free (args);
		ft_exit("");
	}
	while (args[i])
	{
		if (args[i][0] == '-' && args[i][1] == '\0')
			ft_exit("Error\n");
		data->number[i] = ft_atoi_restrict(args[i]);
		i++;
	}
	transform_in_order(data->number, nb_arg);
	create_new_list(data, args);
	i = 0;
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free (args);
}

void	transform_in_order(int *tab, int nb_arg)
{
	int	i;
	int	j;
	int	*new_tab;

	i = 0;
	j = 0;
	new_tab = malloc(sizeof (int) * nb_arg);
	if (!new_tab)
	{
		free (tab);
		ft_exit("");
	}
	copy_tab(tab, new_tab, nb_arg);
	ft_sort_int_tab(new_tab, nb_arg);
	while (i < nb_arg && j < nb_arg)
	{
		if (tab[i] == new_tab[j])
		{
			tab[i] = j;
			i++;
			j = -1;
		}
		j++;
	}
	free (new_tab);
}
