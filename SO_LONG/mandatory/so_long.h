/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 17:46:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_dim
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
}	t_dim;

typedef struct s_flow
{
	int		count;
	int		max;
	void	*me_1flower;
	void	*me_2flower;
	void	*me_3flower;
	void	*me_4flower;
}	t_flow;

typedef struct s_img
{
	void	*snow;
	void	*tree;
	void	*brieuc;
	void	*brieuc_happy;
	void	*flower;
	void	*me;
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
char	*get_map_in_line(char *argv);
void	init_sprites(t_data *data);
void	read_map(t_data *data, t_dim *dimensions, char *line);
void	set_obstacle(t_data *data, t_dim *dimensions);
void	set_character(t_data *data, t_dim *dimensions);
void	set_end(t_data *data, t_dim *dimensions);
void	set_collectible(t_data *data, t_dim *dimensions);

void	errors(t_data data, char *line);
void	check_wall(char *line);
void	check_error_name(char *argv);

void	ft_exit(char *line, char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	create_tab(t_data *data, void **tab);
void	ft_destroy_all(t_data *data);

#endif
