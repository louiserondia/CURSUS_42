/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/10 12:42:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **lst)
{
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		sa(lst);
}

void	sort_three(t_list **lst)
{
	int	i;
	int	j;
	int	k;

	i = *(int *)(*lst)->content;
	j = *(int *)(*lst)->next->content;
	k = *(int *)(*lst)->next->next->content;
	if (i < j && i < k && j > k)			// 1 3 2
	{
		sa(lst);
		ra(lst);
	}
	else if (i < j && i > k  && j > k)		// 2 3 1
		rra(lst);
	else if (i > j && i < k && j < k)		// 2 1 3
		sa(lst);
	else if (i > j && i > k && j > k)		// 3 2 1
	{
		sa(lst);
		rra(lst);
	}
	else if (i > j && i > k && j < k)		// 3 1 2
		ra(lst);
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

void	sort_five(t_data *data, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = get_indix(*stack_a, 0);
	if (i > data->argc / 2)
		function_until_max(stack_a, data->argc, i, rra);
	else if (i <= data->argc / 2)
		function_until_zero(stack_a, i, ra);
	pb(stack_a, stack_b);
	if (data->argc == 5)
	{
		i = get_indix(*stack_a, 1);
		if (i > data->argc / 2)
			function_until_max(stack_a, data->argc, i, rra);
		else if (i <= data->argc / 2)
			function_until_zero(stack_a, i, ra);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
