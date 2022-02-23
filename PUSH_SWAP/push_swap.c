/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:00:05 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/23 13:56:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	void	*tmp;

	if (data->stack_a->content && data->stack_a->next)
	{
		tmp = data->stack_a->next->content;
		data->stack_a->next->content = data->stack_a->content;
		data->stack_a->content = tmp;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_data *data)
{
	void	*tmp;

	if (data->stack_b->content && data->stack_b->next)
	{
		tmp = data->stack_b->next->content;
		data->stack_b->next->content = data->stack_b->content;
		data->stack_b->content = tmp;
		write(1, "sb\n", 3);
	}
}

void	swap_ab(t_data *data)
{
	void	*tmp;

	if (data->stack_a->content && data->stack_a->next)
	{
		tmp = data->stack_a->next->content;
		data->stack_a->next->content = data->stack_a->content;
		data->stack_a->content = tmp;
		write(1, "sa\n", 3);
	}
	if (data->stack_b->content && data->stack_b->next)
	{
		tmp = data->stack_b->next->content;
		data->stack_b->next->content = data->stack_b->content;
		data->stack_b->content = tmp;
		write(1, "sb\n", 3);
	}
}

void	push_b(t_data *data)
{
	t_list	*new;
	
	if (data->stack_a && data->stack_b)
	{
		new = ft_lstnew(data->stack_a->content);
		ft_lstadd_front(&data->stack_b, new);
		write(1, "pb\n", 3);
	}
	else if (!data->stack_b && data->stack_a)
	{
		// data->stack_b = ft_lstnew(data->stack_a->content);
		// new = ft_lstnew(&data->stack_a->content);
		ft_lstadd_front(&data->stack_b, ft_lstnew(data->stack_a->content));
	}
}

