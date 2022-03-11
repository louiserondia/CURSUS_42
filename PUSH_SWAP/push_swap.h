/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/11 21:14:15 by lrondia          ###   ########.fr       */
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

typedef struct s_action
{
	int	pos_a;
	int	pos_b;
}	t_action;

// utils
void	ft_exit(char *str);
int		ft_atoi_restrict(char *str);
size_t	same_str(char *s1, char *s2);
t_list	*ft_lstpenultiem(t_list *stack);
int		ft_lstexist(t_list *lst);
int		ft_lstlen(t_list *lst);


void	print_data(t_data data);


void	parsing(t_data *data, char **argv);
char	**get_all_args(char **argv);
void	check_duplicate(char **args);
void	get_into_stack(char **args, t_data *data);
void	transform_in_order(int *tab, t_data *data);
void	ft_sort_int_tab(int *tab, int size);
int		get_indix(t_list *stack, int nb);
void	push_two_firsts(t_data *data);
int		find_headlist(t_list *stack);
int		get_position(int nb, t_list **stack_b, int headlist);
int		get_score(t_action action, t_data *data);
t_action	find_best_action(t_action best, t_data *data, int headlist);
void	make_actions(t_action best, t_data *data);
void	action_a(int i, t_data *data);
void	action_b(int i, t_data *data);
void	double_rotate(t_action best, t_data *data);
void	double_reverse_rotate(t_action best, t_data *data, int len_a, int len_b);

//operations

int		push(t_list **old, t_list **new);
int		swap(t_list **stack);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
void	pa(t_data *data);						//push
void	pb(t_data *data);
void	sa(t_data *data);						//swap
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);						//vers le haut
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);						//vers le bas
void	rrb(t_data *data);
void	rrr(t_data *data);

int		is_sorted(t_list *lst);
void	send_sort(t_data *data);
void	sort_three(t_data *data);
void	sort_five(t_data *data);
void	sort_big(t_data *data);

#endif
