/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:42:45 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:25:35 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_actions(t_action best, t_data *data)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(data->stack_a);
	len_b = ft_lstlen(data->stack_b);
	if (best.pos_a <= len_a / 2 && best.pos_b <= len_b / 2)
		double_rotate(best, data);
	else if (best.pos_a > len_a / 2 && best.pos_b > len_b / 2)
		double_rev_rotate(best, data, len_a, len_b);
	else
	{
		action_a(best.pos_a, data);
		action_b(best.pos_b, data);
	}
}

void	action_a(int i, t_data *data)
{
	int	len;

	len = ft_lstlen(data->stack_a);
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
}

void	action_b(int i, t_data *data)
{
	int	len;

	len = ft_lstlen(data->stack_b);
	if (i > len / 2)
	{
		while (i < len)
		{
			rrb(data);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(data);
			i--;
		}
	}
}

void	double_rotate(t_action best, t_data *data)
{
	int	i;

	i = 0;
	while (i < best.pos_a && i < best.pos_b)
	{
		rr(data);
		i++;
	}
	while (i < best.pos_a)
	{
		ra(data);
		i++;
	}	
	while (i < best.pos_b)
	{
		rb(data);
		i++;
	}
}

void	double_rev_rotate(t_action best, t_data *data, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (i < len_b - best.pos_b && i < len_a - best.pos_a)
	{
		rrr(data);
		i++;
	}	
	while (i < len_a - best.pos_a)
	{
		rra(data);
		i++;
	}
	while (i < len_b - best.pos_b)
	{
		rrb(data);
		i++;
	}
}
