/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:56:12 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/25 18:09:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **old, t_list **new)
{
	t_list	*elem;

	if (ft_lstexist(*old))
	{
		elem = *old;
		*old = elem->next;
		ft_lstadd_front(new, elem);
		return (1);
	}
	return (0);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a))
		write (1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b))
		write (1, "pb\n", 3);
}
