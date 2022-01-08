/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:44:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/08 18:44:42 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	int	i;

	i = 0;
	while (alst[i])
		i++;
	while (i > 0)
	{
		alst[i] = alst[i - 1];
		i--;
	}
	alst[0] = new;
}
