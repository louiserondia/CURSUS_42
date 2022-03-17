/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:15:43 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/17 12:42:06 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	data.stack_a = NULL;
	data.stack_b = NULL;
	parsing(&data, argv);
	if (is_sorted(data.stack_a))
		return (0);
	send_sort(&data);
	free (data.number);
	ft_lstclear(&data.stack_a, NULL);
	ft_lstclear(&data.stack_b, NULL);
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
