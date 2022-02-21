/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/21 17:28:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct	s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		argc;
}	t_data;

void	parsing(t_data *data, char **argv);
void	ft_exit(char *str);
char 	**get_all_args(char **argv);
void	check_duplicate(char **args);
void	get_into_stack(char **args, t_data *data);


#endif
