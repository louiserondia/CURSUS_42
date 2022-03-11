/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:29:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/11 20:57:29 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*elem;

	if (ft_lstexist(*stack) == 2)
	{
		elem = *stack;
		*stack = elem->next;
		elem->next = NULL;
		ft_lstadd_back(stack, elem);
		return (1);
	}
	return (0);
}

void	ra(t_data *data)
{
	rotate(&data->stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	rotate(&data->stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	write(1, "rr\n", 3);
}
