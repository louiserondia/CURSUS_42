




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


