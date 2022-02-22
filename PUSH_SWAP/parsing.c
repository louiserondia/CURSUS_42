/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:18:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/22 16:39:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_data *data, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = get_all_args(argv);
	while (args[i])
		i++;
	data->argc = i;
	check_duplicate(args);
	get_into_stack(args, data);
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
				ft_exit("Error\n");
			j++;
		}	
		i++;
	}
}

char	**get_all_args(char **argv)
{
	int		i;
	char	*all_args;
	char	**args;

	i = 1;
	all_args = "";
	while (argv[i])
	{
		all_args = ft_strjoin(all_args, argv[i]);
		all_args = ft_strjoin(all_args, " ");
		i++;
	}
	args = ft_split(all_args, ' ');
	return (args);
}

void	get_into_stack(char **args, t_data *data)
{
	int	i;
	int	sign;
	int	*number;

	number = malloc (sizeof (int) * data->argc);
	if (!number)
		ft_exit("");
	i = 0;
	while (args[i])
	{
		sign = 1;
		number[i] = ft_atoi_restrict(args[i]);
		ft_lstadd_back(&data->stack_a, ft_lstnew(&number[i]));
		i++;
	}
	free (number);
}
