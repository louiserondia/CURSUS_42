/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/21 19:53:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*tree;
	char	*tree_path;
	void	*snow;
	char	*snow_path;
	void	*wood;
	char	*wood_path;
	void	*me;
	char	*me_path;
}	t_data;

typedef struct s_dim
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
}	t_dim;

int		ft_key_hook(int keycode, t_data *data);
void	ft_exit(char *str);

#endif
