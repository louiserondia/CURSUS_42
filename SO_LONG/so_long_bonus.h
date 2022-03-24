/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/24 17:39:28 by lrondia          ###   ########.fr       */
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
}	t_dim;

typedef struct s_num
{
	void	*one;
	char	*one_path;
	void	*two;
	char	*two_path;
	void	*three;
	char	*three_path;
	void	*four;
	char	*four_path;
}	t_num;

typedef struct s_flow
{
	int		count;
	int		max;
	void	*flow0;
	char	*flow0_path;
	void	*flow1;
	char	*flow1_path;
	void	*flow2;
	char	*flow2_path;
	void	*flow3;
	char	*flow3_path;
	void	*flow4;
	char	*flow4_path;
}	t_flow;

typedef struct s_heart
{
	int		count_me;
	int		count_monster;
	void	*heart1;
	char	*heart1_path;
	void	*heart2;
	char	*heart2_path;
	void	*heart3;
	char	*heart3_path;
}	t_heart;

typedef struct s_monst
{
	int		left;
	int		right;
	void	*chimere_left;
	char	*chimere_left_path;
	void	*chimere_right;
	char	*chimere_right_path;
}	t_monst;

typedef struct s_img
{
	void	*snow;
	char	*snow_path;
	void	*tree;
	char	*tree_path;
	void	*brieuc;
	char	*brieuc_path;
	void	*flower;
	char	*flower_path;
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
	t_heart	heart;
	t_monst	monster;
	t_num	number;
}	t_data;

int		ft_key_hook(int keycode, t_data *data);
char	*get_map_in_line(char *argv);
void	init_sprites(t_data *data);
void	read_map(t_data *data, t_dim *dimensions, char *line);
void	set_obstacle(t_data *data, t_dim *dim);
void	set_character(t_data *data, t_dim *dim);
void	set_end(t_data *data, t_dim *dim);
void	set_collectible(t_data *data, t_dim *dim);
void	set_monster(t_data *data, t_dim *dim);
void	set_hearts(t_data *data, t_dim *dim, int count);
void	set_number(t_data *data, t_dim *dim);

void	set_character_0flow(t_data *data, t_dim *dim);
void	set_character_1flow(t_data *data, t_dim *dim);
void	set_character_2flow(t_data *data, t_dim *dim);
void	set_character_3flow(t_data *data, t_dim *dim);
void	set_character_4flow(t_data *data, t_dim *dim);

void	set_monster_left(t_data *data, t_dim *dim);
void	set_monster_right(t_data *data, t_dim *dim);

void	errors(t_data data, char *line);
void	check_wall(char *line);
void	check_error_name(char *argv);

void	ft_exit(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);

#endif
