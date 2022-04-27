/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:17:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/27 17:15:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

// typedef struct timeval
// {	
// }	t_time;

typedef struct s_philo
{
	int	state;						//0 = thinking	1 = eating	2 = sleeping
}	t_philo;

typedef struct s_table
{
	t_philo **philo;
	int		nb_philo;
	int		fork_state;				//0 = free		1 = taken
}	t_table;

void	ft_printf_state(t_table *table);
int		ft_atoi_restrict(char *str);

#endif
 