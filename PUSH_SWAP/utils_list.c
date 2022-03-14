/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:27:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:33:22 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstpenultiem(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

int	ft_lstexist(t_list *lst)
{
	if (lst && lst->content && lst->next)
		return (2);
	else if (lst && lst->content && !lst->next)
		return (1);
	else
		return (0);
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

int	find_headlist(t_list *stack)
{
	int		i;
	int		j;
	int		max;
	t_list	*lst;

	i = 0;
	j = 0;
	max = 0;
	lst = stack;
	while (lst)
	{
		if (max < *(int *)lst->content)
		{
			j = i;
			max = *(int *)lst->content;
		}	
		lst = lst->next;
		i++;
	}
	return (j);
}
