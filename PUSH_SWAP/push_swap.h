/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/14 19:31:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*number;
}	t_data;

typedef struct s_action
{
	int	pos_a;
	int	pos_b;
}	t_action;

//			utils

void		ft_exit(char *str);
int			ft_atoi_restrict(char *str);
size_t		same_str(char *s1, char *s2);
t_list		*ft_lstpenultiem(t_list *stack);
int			ft_lstexist(t_list *lst);
int			ft_lstlen(t_list *lst);
int			find_headlist(t_list *stack);
void		check_duplicate(char **args);
void		copy_tab(int *tab, int *new_tab, int nb_arg);
void		ft_sort_int_tab(int *tab, int size);
void		create_new_list(t_data *data, char **args);

//			general functions

void		parsing(t_data *data, char **argv);
char		**get_all_args(char **argv);
void		get_into_stack(char **args, t_data *data, int nb_arg);
void		transform_in_order(int *tab, int nbarg);
int			get_indix(t_list *stack, int nb);
void		operations_five(t_data *data, int i, int len);
int			get_position(int nb, t_list **stack_b, int headlist);
int			get_score(t_action action, t_data *data);
t_action	find_best_action(t_action best, t_data *data);
void		make_actions(t_action best, t_data *data);
void		action_a(int i, t_data *data);
void		action_b(int i, t_data *data);
void		double_rotate(t_action best, t_data *data);
void		double_rev_rotate(t_action best, t_data *data,
				int len_a, int len_b);
void		push_all_back(t_data *data);

//			operations

int			push(t_list **old, t_list **new);
int			swap(t_list **stack);
int			rotate(t_list **stack);
int			reverse_rotate(t_list **stack);
void		pa(t_data *data);
void		pb(t_data *data);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

int			is_sorted(t_list *lst);
void		send_sort(t_data *data);
void		sort_three(t_data *data);
void		sort_five(t_data *data);
void		sort_big(t_data *data);

#endif
