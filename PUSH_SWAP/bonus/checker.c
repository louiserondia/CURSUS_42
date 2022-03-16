/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:02:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/16 21:49:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

void	parsing_terminal(t_data *data)
{
	char	*line;

	line = (char *)1;
	while (line)
	{
		line = get_next_line(0);
		if (!sort_operations(data, line) && line)
		{
			free (line);
			ft_exit("Error\n");
		}
		free (line);
	}
}

void	*sort_operations(t_data *data, char *line)
{
	if (ft_strcmp(line, "sa\n") || ft_strcmp(line, "sb\n")
		|| ft_strcmp(line, "ss\n"))
		operation_swap(data, line);
	else if (ft_strcmp(line, "pa\n") || ft_strcmp(line, "pb\n"))
		operation_push(data, line);
	else if (ft_strcmp(line, "ra\n") || ft_strcmp(line, "rb\n")
		|| ft_strcmp(line, "rr\n"))
		operation_rotate(data, line);
	else if (ft_strcmp(line, "rra\n") || ft_strcmp(line, "rrb\n")
		|| ft_strcmp(line, "rrr\n"))
		operation_reverse_rotate(data, line);
	else
		return (NULL);
	return (line);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	data.stack_a = NULL;
	data.stack_b = NULL;
	parsing(&data, argv);
	if (is_sorted(data.stack_a))
		return (0);
	parsing_terminal(&data);
	if (is_sorted(data.stack_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free (data.number);
	ft_lstclear(&data.stack_a, NULL);
	ft_lstclear(&data.stack_b, NULL);
	// system("leaks checker");
}
