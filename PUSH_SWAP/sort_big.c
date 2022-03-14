/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:43:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:28:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_data *data)
{
	t_action	best;

	pb(data);
	pb(data);
	while (data->stack_a)
	{
		best = find_best_action(best, data);
		make_actions(best, data);
		pb(data);
	}
	push_all_back(data);
}

t_action	find_best_action(t_action best, t_data *data)
{
	int			i;
	int			content;
	int			headlist;
	t_list		*lst;
	t_action	action;

	i = 0;
	lst = data->stack_a;
	headlist = find_headlist(data->stack_b);
	best.pos_a = 0;
	best.pos_b = get_position(*(int *)lst->content, &data->stack_b, headlist);
	while (lst)
	{
		content = *(int *)lst->content;
		headlist = find_headlist(data->stack_b);
		action.pos_a = i;
		action.pos_b = get_position(content, &data->stack_b, headlist);
		if (get_score(action, data) < get_score(best, data))
			best = action;
		i++;
		lst = lst->next;
	}
	return (best);
}

int	get_score(t_action action, t_data *data)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(data->stack_a);
	len_b = ft_lstlen(data->stack_b);
	if (action.pos_a > len_a / 2 && action.pos_b > len_b / 2)
	{
		if (len_a - action.pos_a > len_b - action.pos_b)
			return (len_a - action.pos_a);
		else
			return (len_b - action.pos_b);
	}
	else if (action.pos_a <= len_a / 2 && action.pos_b <= len_b / 2)
	{
		if (action.pos_a > action.pos_b)
			return (action.pos_a);
		else
			return (action.pos_b);
	}
	else if (action.pos_a > len_a / 2 && action.pos_b <= len_b / 2)
		return (len_a - action.pos_a + action.pos_b);
	else
		return (len_b - action.pos_b + action.pos_a);
}

int	get_position(int nb, t_list **stack_b, int headlist)
{
	int		i;
	t_list	*lst;

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
	return (i - 1);
}

void	push_all_back(t_data *data)
{
	int	headlist;

	headlist = find_headlist(data->stack_b);
	if (headlist <= ft_lstlen(data->stack_b) / 2)
	{
		while (headlist-- > 0)
			rb(data);
	}
	else
	{
		while (headlist++ < ft_lstlen(data->stack_b))
			rrb(data);
	}
	while (data->stack_b)
		pa(data);
}
