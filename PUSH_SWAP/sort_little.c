/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 15:55:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = *(int *)data->stack_a->content;
	j = *(int *)data->stack_a->next->content;
	k = *(int *)data->stack_a->next->next->content;
	if (i < j && i < k && j > k)
	{
		sa(data);
		ra(data);
	}
	else if (i < j && i > k && j > k)
		rra(data);
	else if (i > j && i < k && j < k)
		sa(data);
	else if (i > j && i > k && j > k)
	{
		sa(data);
		rra(data);
	}
	else if (i > j && i > k && j < k)
		ra(data);
}

void	sort_five(t_data *data)
{
	int	i;
	int	len;

	i = get_indix(data->stack_a, 0);
	len = ft_lstlen(data->stack_a);
	operations_five(data, i, len);
	if (len == 5)
	{
		len = ft_lstlen(data->stack_a);
		i = get_indix(data->stack_a, 1);
		operations_five(data, i, len);
	}
	sort_three(data);
	pa(data);
	pa(data);
}

void	operations_five(t_data *data, int i, int len)
{
	if (i > len / 2)
	{		
		while (i < len)
		{
			rra(data);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(data);
			i--;
		}
	}
	pb(data);
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
