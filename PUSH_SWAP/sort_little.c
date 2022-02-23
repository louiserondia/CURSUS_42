/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/23 23:07:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two (t_list **lst)
{
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		sa(lst);
}

void	sort_three(t_list **lst)
{
	int	i;
	int	j;
	int	k;

	i = *(int *)(*lst)->content;
	j = *(int *)(*lst)->next->content;
	k = *(int *)(*lst)->next->next->content;
	if (i < j && i < k && j > k)			// 1 3 2
	{
		sa(lst);
		ra(lst);
	}
	else if (i < j && i > k  && j > k)		// 2 3 1
		rra(lst);
	else if (i > j && i < k && j < k)		// 2 1 3
		sa(lst);
	else if (i > j && i > k && j > k)		// 3 2 1
	{
		sa(lst);
		rra(lst);
	}
	else if (i > j && i > k && j < k)		// 3 1 2
		ra(lst);gi
}