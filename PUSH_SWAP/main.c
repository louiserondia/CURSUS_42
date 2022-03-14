/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:15:43 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:26:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	(void) argv;
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (argc <= 1)
		ft_exit("Error\n");
	parsing(&data, argv);
	if (is_sorted(data.stack_a))
		return (0);
	send_sort(&data);
	free (data.number);
	ft_lstclear(&data.stack_a, NULL);
	ft_lstclear(&data.stack_b, NULL);
}

int	is_sorted(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (*(int *)lst->content != i)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

void	send_sort(t_data *data)
{
	int	len;

	len = ft_lstlen(data->stack_a);
	if (len == 2)
		sa(data);
	else if (len == 3)
		sort_three(data);
	else if (len == 4 || len == 5)
		sort_five(data);
	else if (len > 5)
		sort_big(data);
}
