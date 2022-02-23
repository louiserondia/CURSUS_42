/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/22 21:58:20 by lrondia          ###   ########.fr       */
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

void	parsing(t_data *data, char **argv);
void	ft_exit(char *str);
char	**get_all_args(char **argv);
void	check_duplicate(char **args);
void	get_into_stack(char **args, t_data *data);
int		ft_atoi_restrict(char *str);
size_t	same_str(char *s1, char *s2);
void	ft_lstdel_front(t_list **alst);
void	swap_a(t_data *data);	// sa
void	swap_b(t_data *data);	// sb
void	swap_ab(t_data *data);	// ss
void	push_a(t_data *data);
void	push_b(t_data *data);

#endif
