/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:43:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/11 21:14:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_data *data)
{
	t_action	best;
	int			headlist;

	push_two_firsts(data);
	headlist = find_headlist(data->stack_b);
	while (data->stack_a)
	{
		best = find_best_action(best, data, headlist);
		make_actions(best, data);
		pb(data);
		headlist = find_headlist(data->stack_b);
	}
}

int	get_score(t_action action, t_data *data)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(data->stack_a);
	len_b = ft_lstlen(data->stack_b);
	if (action.pos_a > len_a / 2 && action.pos_b > len_b / 2)
	{
		if (action.pos_b > action.pos_a)
			return (len_a - action.pos_a);
		else
			return (len_b - action.pos_b);
	}
	if (action.pos_a <= len_a / 2 && action.pos_b <= len_b / 2)
	{
		if (action.pos_a > action.pos_b)
			return (len_a - action.pos_a);
		else
			return (len_b - action.pos_b);
	}
	if (action.pos_a > len_a / 2)
		action.pos_a = len_a - action.pos_a;
	if (action.pos_b > len_b / 2)
		action.pos_b = len_b - action.pos_b;
	return (action.pos_a + action.pos_b);
}

t_action	find_best_action(t_action best, t_data *data, int headlist)
{
	int			i;
	int			content;
	t_action	action;

	i = 0;
	while (data->stack_a)
	{
		content = *(int *)data->stack_a->content;
		action.pos_a = i;
		action.pos_b = get_position(content, &data->stack_b, headlist);
		if (get_score(action, data) < get_score(best, data))
			best = action;
		i++;
		data->stack_a = data->stack_a->next;	
	}
	return (best);
}

int	get_position(int nb, t_list **stack_b, int headlist)
{
	int		i;
	t_list *lst;

	i = 0;
	lst = *stack_b;
	while (lst && i++ < headlist)
		lst = lst->next;
	while (lst && nb < *(int *)lst->content)
	{
		i++;
		lst = lst->next;
	}
	if (!lst)
	{
		i = 0;
		lst = *stack_b;
		while (lst && i++ < headlist && nb < *(int *)lst->content)
			lst = lst->next;
	}
	return (i);
}

void	push_two_firsts(t_data *data)
{
	pb(data);
	pb(data);
	if (is_sorted(data->stack_b))
		sb(data);
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
	return (j);
}
