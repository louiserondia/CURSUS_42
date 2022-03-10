




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
