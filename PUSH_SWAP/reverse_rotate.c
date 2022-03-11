/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:29:30 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/11 20:57:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*elem;

	if (ft_lstexist(*stack) == 2)
	{
		elem = ft_lstlast(*stack);
		ft_lstpenultiem(*stack)->next = NULL;
		ft_lstadd_front(stack, elem);
		return (1);
	}
	return (0);
}

void	rra(t_data *data)
{
	reverse_rotate(&data->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	reverse_rotate(&data->stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	write (1, "rrr\n", 4);

}
