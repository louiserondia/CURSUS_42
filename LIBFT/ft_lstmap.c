/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:57:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/10 20:20:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**start;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	start = &new_list;
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if (!new_list)
		{
			ft_lstclear(start, del);
			return (NULL);
		}
		ft_lstadd_back(start, new_list);
		lst = lst->next;
	}
	return (*start);
}
