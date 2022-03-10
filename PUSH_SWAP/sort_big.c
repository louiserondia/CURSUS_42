/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:43:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/10 17:42:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	position;
	int	len;
	int headlist;
	int	j;

	position = 0;
	push_two_firsts(stack_a, stack_b);
	headlist = find_headlist(*stack_b);
	j = 0;
	
	while (*stack_a)
	{
		if (j == 4)
			break;
		len = ft_lstlen(*stack_b);
		position = new_get_position(*(int *)(*stack_a)->content, stack_b, headlist);
		printf("position [%d]: %d\n", *(int *)(*stack_a)->content, position);
		if (position == 0 || position == len)
			;
		else if (position > len / 2)
			function_until_max(stack_b, len, position, rrb);
		else if (position <= len / 2)
			function_until_zero(stack_b, position, rb);
		pb(stack_a, stack_b);
		headlist = find_headlist(*stack_b);
		j++;
	}
}

int	ft_lstlen(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	get_position(int nb, t_list *stack_b)
{
	int	i;

	i = 0;
	while (stack_b && nb < *(int *)stack_b->content)
	{
		i++;
		stack_b = stack_b->next;
	}
	return (i);
}

int	new_get_position(int nb, t_list **stack_b, int headlist)
{
	int		i;
	t_list *lst;

	i = 0;
	lst = *stack_b;
	while (lst && i <= headlist)
	{
		lst = lst->next;
		i++;
	}
	while (lst && nb < *(int *)lst->content)
	{
		i++;
		lst = lst->next;
	}
	if (!lst)
	{
		i = 0;
		lst = *stack_b;
		while (lst && i <= headlist && nb < *(int *)lst->content)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

void	push_two_firsts(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (*(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
		sa(stack_b);
}

int	find_headlist(t_list *stack)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (stack)
	{
		if (max < *(int *)stack->content)
		{
			j = i;
			max = *(int *)stack->content;
		}	
		stack = stack->next;
		i++;
	}
	return (i);
}
