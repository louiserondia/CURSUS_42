/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/25 18:11:31 by lrondia          ###   ########.fr       */
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
	if (i < j && i < k && j > k)	// 1 3 2
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

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int i;
	int j;
	int k;
	int l;
	
	i = *(int *)(*stack_a)->content;
	j = *(int *)(*stack_a)->next->content;
	k = *(int *)(*stack_a)->next->next->content;
	l = *(int *)(*stack_a)->next->next->next->content;
	
	if (i == 0 && j == 1 && k == 2 && l == 3)
		return ;
	if (i == 0)
		pb(stack_a, stack_b);
	else if (j == 0)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (k == 0)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_a);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
}
