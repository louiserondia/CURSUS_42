/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/11 21:11:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = *(int *)data->stack_b->content;
	j = *(int *)data->stack_a->next->content;
	k = *(int *)data->stack_a->next->next->content;
	if (i < j && i < k && j > k)			// 1 3 2
	{
		sa(data);
		ra(data);
	}
	else if (i < j && i > k  && j > k)		// 2 3 1
		rra(data);
	else if (i > j && i < k && j < k)		// 2 1 3
		sa(data);
	else if (i > j && i > k && j > k)		// 3 2 1
	{
		sa(data);
		rra(data);
	}
	else if (i > j && i > k && j < k)		// 3 1 2
		ra(data);
}


void	sort_five(t_data *data)
{
	int	i;
	int	len;

	i = get_indix(data->stack_a, 0);
	len = ft_lstlen(data->stack_a);
	if (i > data->argc / 2)
	{		
		while (i++ < len)
			rra(data);
	}
	else if (i <= data->argc / 2)
	{
		while (i-- < 0)
		ra(data);
	}
	pb(data);
	if (data->argc == 5)
	{
		i = get_indix(data->stack_a, 1);
		if (i > data->argc / 2)
		{
			while (i++ < len)
				rra(data);
		}
		else if (i <= data->argc / 2)
		{
			while (i-- < 0)
			ra(data);
		}
		pb(data);
	}
	sort_three(data);
	pa(data);
	pa(data);
}

int	get_indix(t_list *stack, int nb)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (*(int *)stack->content == nb)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}


	// function_until_zero(&data->stack_a, i, ra);
	// function_until_max(&data->stack_a, data->argc, i, rra);
	// function_until_max(data, &data->stack_a, data->argc, i, rra);
	// function_until_zero(&data->stack_a, i, ra);