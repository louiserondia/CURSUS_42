/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/25 17:39:22 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

#include <stdio.h>

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		argc;
}	t_data;

// utils
void	ft_exit(char *str);
int		ft_atoi_restrict(char *str);
size_t	same_str(char *s1, char *s2);
t_list	*ft_lstpenultiem(t_list *stack);
int		ft_lstexist(t_list *lst);


void	parsing(t_data *data, char **argv);
char	**get_all_args(char **argv);
void	check_duplicate(char **args);
void	get_into_stack(char **args, t_data *data);
void	transform_in_order(int *tab, t_data *data);
void	ft_sort_int_tab(int *tab, int size);

//operations

int		push(t_list **old, t_list **new);
int		swap(t_list **stack);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
void	pa(t_list **stack_b, t_list **stack_a);	//push
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack);						//swap
void	sb(t_list **stack);
void	ss(t_data *data);
void	ra(t_list **stack);						//vers le haut
void	rb(t_list **stack);
void	rr(t_data *data);
void	rra(t_list **stack);					//vers le bas
void	rrb(t_list **stack);
void	rrr(t_data *data);

void	sort_two (t_list **lst);
void	sort_three(t_list **lst);
void	sort_four(t_list **stack_a, t_list **stack_b);

#endif
