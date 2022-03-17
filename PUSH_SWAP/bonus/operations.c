/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:17:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/17 12:18:39 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	operation_swap(t_data *data, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		swap(&data->stack_a);
	else if (ft_strcmp(line, "sb\n"))
		swap(&data->stack_b);
	else if (ft_strcmp(line, "ss\n"))
	{
		swap(&data->stack_a);
		swap(&data->stack_b);
	}
}

void	operation_push(t_data *data, char *line)
{
	if (ft_strcmp(line, "pa\n"))
		push(&data->stack_b, &data->stack_a);
	else if (ft_strcmp(line, "pb\n"))
		push(&data->stack_a, &data->stack_b);
}

void	operation_rotate(t_data *data, char *line)
{
	if (ft_strcmp(line, "ra\n"))
		rotate(&data->stack_a);
	else if (ft_strcmp(line, "rb\n"))
		rotate(&data->stack_b);
	else if (ft_strcmp(line, "rr\n"))
	{
		rotate(&data->stack_a);
		rotate(&data->stack_b);
	}
}

void	operation_reverse_rotate(t_data *data, char *line)
{
	if (ft_strcmp(line, "rra\n"))
		reverse_rotate(&data->stack_a);
	else if (ft_strcmp(line, "rrb\n"))
		reverse_rotate(&data->stack_b);
	else if (ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate(&data->stack_a);
		reverse_rotate(&data->stack_b);
	}
}
