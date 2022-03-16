/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:56:12 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/11 20:56:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **old, t_list **new)
{
	t_list	*elem;

	if (ft_lstexist(*old) >= 1)
	{
		elem = *old;
		*old = elem->next;
		ft_lstadd_front(new, elem);
		return (1);
	}
	return (0);
}

void	pa(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	write (1, "pa\n", 3);
}

void	pb(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	write (1, "pb\n", 3);
}
