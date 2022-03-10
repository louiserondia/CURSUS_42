/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/10 17:32:22 by lrondia          ###   ########.fr       */
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
int		ft_lstlen(t_list *lst);


void	parsing(t_data *data, char **argv);
char	**get_all_args(char **argv);
void	check_duplicate(char **args);
void	get_into_stack(char **args, t_data *data);
void	transform_in_order(int *tab, t_data *data);
void	ft_sort_int_tab(int *tab, int size);
int		get_indix(t_list *stack, int nb);
int		get_position(int nb, t_list *stack_b);
void	push_two_firsts(t_list **stack_a, t_list **stack_b);
void	function_until_zero(t_list **stack, int position, void (*f)(t_list **));
void	function_until_max(t_list **stack, int len, int position, void (*f)(t_list **));
int		find_headlist(t_list *stack);

int		new_get_position(int nb, t_list **stack_b, int headlist);

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

int		is_sorted(t_list *lst);
void	send_sort(t_data *data);
void	sort_two (t_list **lst);
void	sort_three(t_list **lst);
void	sort_five(t_data *data, t_list **stack_a, t_list **stack_b);
void	sort_big(t_list **stack_a, t_list **stack_b);

#endif
