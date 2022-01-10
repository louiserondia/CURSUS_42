/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:44:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/10 19:50:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		return (0);
	a->content = content;
	a->next = NULL;
	return (a);
}
