/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/22 20:36:30 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_dim
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	pos_me;
}	t_dim;

typedef struct s_flow
{
	int		count;
	int		max;
	void	*me_1flower;
	char	*me_1flower_path;
	void	*me_2flower;
	char	*me_2flower_path;
	void	*me_3flower;
	char	*me_3flower_path;
	void	*me_4flower;
	char	*me_4flower_path;
}	t_flow;

typedef struct s_img
{
	void	*snow;
	char	*snow_path;
	void	*tree;
	char	*tree_path;
	void	*wood;
	char	*wood_path;
	void	*flower;
	char	*flower_path;
	void	*me;
	char	*me_path;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*line;
	int		operations;
	t_img	img;
	t_dim	dim;
	t_flow	flow;
}	t_data;

int		ft_key_hook(int keycode, t_data *data);
void	read_map(t_data *data, t_dim *dimensions, char *line);
void	ft_exit(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	set_obstacle(t_data *data, t_dim *dimensions);
void	set_character(t_data *data, t_dim *dimensions);
void	set_end(t_data *data, t_dim *dimensions);
void	set_collectible(t_data *data, t_dim *dimensions);
int		errors(char *line);
void	count_horizontal(char *line);
void	error_name(char *argv);

#endif
