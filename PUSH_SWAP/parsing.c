/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:18:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/21 17:56:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			if (strstr(args[i], args[j]))
				ft_exit("Error\n");
			j++;
		}	
		i++;
	}
}

char **get_all_args(char **argv)
{
	int		i;
	char	*all_args;
	char	**args;

	i = 1;
	all_args = "";
	while(argv[i])
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
	int	j;
	int	sign;
	int	*number;

	number = malloc (sizeof (int) * data->argc);
	if (!number)
		ft_exit("");
	i = 0;
	while (args[i])
	{
		j = 0;
		sign = 1;
		number[i] = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-' && j == 0)
				sign *= -1;
			else if (args[i][j] >= '0' && args[i][j] <= '9')
				number[i] = number[i] * 10 + (args[i][j] - '0');
			else
				ft_exit("Error\n");
			j++;
		}
		printf("number : %d\n", number[i]);
		if (number[i] < 0 || j > 10 || number[i] > 2147483647)
			ft_exit("Error\n");
		number[i] *= sign;
		ft_lstadd_back(&data->stack_a, ft_lstnew(&number[i]));
		i++;
	}
	free (number);
}
