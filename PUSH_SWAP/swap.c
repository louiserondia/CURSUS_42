/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:00:05 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/10 17:09:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	void	*tmp;

	if (ft_lstexist(*stack) == 2)
	{
		tmp = (*stack)->next->content;
		(*stack)->next->content = (*stack)->content;
		(*stack)->content = tmp;
		return (1);
	}
	return (0);
}

void	sa(t_list **stack)
{
	swap(stack);
	write (1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(stack);
	write (1, "sb\n", 3);
}

void	ss(t_data *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	write(1, "ss\n", 3);
}
