/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/10 17:00:39 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}		
	exit (0);
}

int	ft_atoi_restrict(char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	res = 0;
	s = 1;
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		ft_exit("Error\n");
	if (res > 2147483647 || res < -2147483648 || (res == -1 && s == 1))
		ft_exit("Error\n");
	res *= s;
	return (res);
}

size_t	same_str(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[j] == '0' && s1[j])
		j++;
	while (s2[k] == '0' && s2[k])
		k++;
	while (s1[i + j] == s2[i + k] && s1[i + j] && s2[i + k])
		i++;
	if (i == ft_strlen(s1) - j && i == ft_strlen(s2) - k)
		return (1);
	return (0);
}

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
