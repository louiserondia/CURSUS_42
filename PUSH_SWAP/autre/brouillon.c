




printf("position [%d]: %d\n", *(int *)(*stack_a)->content, position);
printf("len : %d\n", len);

while (*stack_a)
{
	printf("a : %d\n", *(int *)(*stack_a)->content);
	*stack_a = (*stack_a)->next;
}
printf("\n");
while (*stack_b)
{
	printf("b : %d\n", *(int *)(*stack_b)->content);
	*stack_b = (*stack_b)->next;
}


	int	j;
	j = 0;
	if (j == 4)
	break;
	j++;







0) fonction qui calcule la tete de liste 
1) faire un compteur de position qui commence a la tete de liste



		printf("head : %d\n", headlist);












if (position == 0)
			;
		else if (position == len)
			rb(stack_b);
		else if (position > len / 2)
			function_until_max(stack_b, len + 1, position, rb);
		else if (position <= len / 2)
			function_until_zero(stack_b, position, rrb);















void	function_until_max(t_list **stack, int len, int position, void (*f)(t_list **))
{
	while (position < len)
	{
		f(stack);
		position++;
	}
}

void	function_until_zero(t_list **stack, int position, void (*f)(t_list **))
{
	while (position > 0)
	{
		f(stack);
		position--;
	}
}














int	compare_firsts(t_list **stack_a, t_list **stack_b, int headlist)
{
	int	first;
	int	second;
	
	if (ft_lstlen(*stack_a) == 1)
	{
		first = get_position(*(int *)(*stack_a)->content, stack_b, headlist);
		return (first);
	}
	else if (ft_lstlen(*stack_a) >= 2)
	{
		first = get_position(*(int *)(*stack_a)->content, stack_b, headlist);
		second = get_position(*(int *)(*stack_a)->next->content, stack_b, headlist);
		if (first <= second + 1)
			return (first);
		else
		{
			sa(stack_a);
			return (second);
		}
	}
	return (0);
}























int	compare_rotate_all(t_list **stack_a, t_list **stack_b, int headlist)
{
	int		pos_a;
	int		pos_b;
	int		min;
	int		j;
	t_list	*lst;
	
	pos_a = 0;
	j = 0;
	lst = *stack_a;
	min = get_position(*(int *)lst->content, stack_b, headlist);
	while (lst && pos_a < ft_lstlen(*stack_a) / 2)
	{
		pos_b = get_position(*(int *)lst->content, stack_b, headlist);
		if (pos_b <= ft_lstlen(*stack_b) && pos_b + pos_a < min)
		{
			min = pos_b;
			j = pos_a;		
		}
		else if (pos_b > ft_lstlen(*stack_b) && (ft_lstlen(*stack_b) - pos_b + 1 + pos_a < min))
		{
			min = pos_b;
			j = pos_a;		
		}
		pos_a++;
		lst = lst->next;
	}
	while (lst)
	{
		pos_b = get_position(*(int *)lst->content, stack_b, headlist);
		if (pos_b <= ft_lstlen(*stack_b) && (pos_b + pos_a + 1 < min))
		{
			min = pos_b;
			j = ft_lstlen(*stack_a) - pos_a;		
		}
		else if (pos_b > ft_lstlen(*stack_b) && (ft_lstlen(*stack_b)) - pos_b + 1 + pos_a < min)
		{
			min = pos_b;
			j = ft_lstlen(*stack_a) - pos_a;	
		}
		pos_a--;
		lst = lst->next;
	}
	if (j > ft_lstlen(*stack_a) / 2)
		function_until_max(stack_a, ft_lstlen(*stack_a), j, rra);
	else if (j <= ft_lstlen(*stack_a) / 2)
		function_until_zero(stack_a, j, ra);
	return (min);
}











operation_b = get_position(*(int *)lst->content, stack_b, headlist);
if (operation_b == 0 || operation_b == ft_lstlen(*stack_b))
	;
else if (operation_b > ft_lstlen(*stack_b) / 2)
	function_until_max(stack_b, ft_lstlen(*stack_b), operation_b, rrb);
else if (operation_b <= ft_lstlen(*stack_b) / 2)
	function_until_zero(stack_b, operation_b, rb);








void	push_two_firsts(t_data *data)
{
	pb(data);
	pb(data);
	if (!is_sorted(data->stack_b))
		sb(data);
}



	// printf("headlist :%d\n", headlist);
		// printf("get score action :%d\n", score1);
		// printf("get score best :%d\n", score2);
		// printf("action pos_a :%d\n", action.pos_a);
		// printf("action pos_b :%d\n", action.pos_b);
		// printf("best pos_a :%d\n", best.pos_a);
		// printf("best pos_b :%d\n\n", best.pos_b);
		// printf("i :%d\n", i);
		// printf("len / 2 :%d\n", len / 2);

while (i < len_a - best.pos_a && i < len_b - best.pos_b)
	{
		rrr(data);
		i++;
	}
	while (i < best.pos_a)
	{
		rra(data);
		i++;
	}
	while (i < best.pos_b)
	{
		rrb(data);
		i++;
	}



	while (i < best.pos_a && i < best.pos_b)
	{
		rrr(data);
		i++;
	}
	while (i < best.pos_a)
	{
		rra(data);
		i++;
	}
	while (i < best.pos_b)
	{
		rrb(data);
		i++;
	}











void	sort_three(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = *(int *)data->stack_a->content;
	j = *(int *)data->stack_a->next->content;
	k = *(int *)data->stack_a->next->next->content;
	if (i < j && i < k && j > k)							// 1 3 2
	{
		sa(data);
		ra(data);
	}
	else if (i < j && i > k  && j > k)						// 2 3 1
		rra(data);
	else if (i > j && i < k && j < k)						// 2 1 3
		sa(data);
	else if (i > j && i > k && j > k)						// 3 2 1
	{
		sa(data);
		rra(data);
	}
	else if (i > j && i > k && j < k)		// 3 1 2
		ra(data);
}









i = get_indix(data->stack_a, 1);
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





	if (i > len / 2)
	{		
		while (i < len)
		{
			rra(data);
			i++;
		}
	}
	else if (i <= len / 2)
	{
		while (i > 0)
		{
			ra(data);
			i--;
		}
	}
	pb(data);









void	print_data(t_data data)
{
	while (data.stack_a)
	{
		printf("a : %d\n", *((int *)data.stack_a->content));
		data.stack_a = data.stack_a->next;
	}

	printf("\n");

	while (data.stack_b)
	{
		printf("b : %d\n", *(int *)data.stack_b->content);
		data.stack_b = data.stack_b->next;
	}
}



	printf("number : %ld\n", res);



|| res < -2147483648 || (res == -1 && s == 1)



#include <stdio.h>

print_data(data);

void	print_data(t_data data)
{
	while (data.stack_a)
	{
		printf("a : %d\n", *((int *)data.stack_a->content));
		data.stack_a = data.stack_a->next;
	}

	printf("\n");

	while (data.stack_b)
	{
		printf("b : %d\n", *(int *)data.stack_b->content);
		data.stack_b = data.stack_b->next;
	}
}




// sa(&data);
// write(1, "pr\n", 5);


int    check_format(char *line)
{
    if (ft_strcmp(line, "sa\n") || ft_strcmp(line, "sb\n") || ft_strcmp(line, "ss\n"))
        return (1);
    else if (ft_strcmp(line, "pa\n") || ft_strcmp(line, "pb\n"))
        return (1);
    else if (ft_strcmp(line, "ra\n") || ft_strcmp(line, "rb\n") || ft_strcmp(line, "rr\n"))
        return (1);
    else if (ft_strcmp(line, "rra\n") || ft_strcmp(line, "rrb\n") || ft_strcmp(line, "rrr\n"))
        return (1);
    else if (!line)
        return (1);
    else
        return (0);
}


if (!check_format(line) && line)
ft_exit("Error\n");


