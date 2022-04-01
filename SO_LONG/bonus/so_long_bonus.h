/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/01 12:12:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef struct s_num
{
	void	*table;
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}	t_num;

typedef struct s_flow
{
	int		count;
	int		max;
	int		orientation;
	void	*flow0;
	void	*flow1;
	void	*flow2;
	void	*flow3;
	void	*flow4;
}	t_flow;

typedef struct s_heart
{
	int		count_me;
	int		count_monster;
	void	*heart1;
	void	*heart2;
	void	*heart3;
}	t_heart;

typedef struct s_monst
{
	int		orientation;
	void	*chimere_left;
	void	*chimere_right;
}	t_monst;

typedef struct s_gun
{
	int		time;
	int		gun_nb;
	void	*left0;
	void	*left1;
	void	*left2;
	void	*left3;
	void	*left4;
	void	*left5;
	void	*left6;
	void	*right0;
	void	*right1;
	void	*right2;
	void	*right3;
	void	*right4;
	void	*right5;
	void	*right6;
	void	*right7;
	void	*flame_left;
	void	*flame_right;
}	t_gun;

typedef struct s_img
{
	void	*snow;
	void	*tree;
	void	*brieuc;
	void	*brieuc_happy;
	void	*flower;
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
	t_gun	gun;
}	t_data;

int		ft_key_hook(int keycode, t_data *data);
char	*get_map_in_line(char *argv);
void	init_sprites(t_data *data);
void	read_map(t_data *data, t_dim *dimensions, char *line);
void	get_dimensions(t_dim *dimensions, char *line);
void	count_flowers(t_data *data, char *line);
int		animate_gun(t_data *data);

void	set_obstacle(t_data *data, t_dim *dim);
void	set_character(t_data *data, t_dim *dim);
void	set_end(t_data *data, t_dim *dim);
void	set_collectible(t_data *data, t_dim *dim);
void	set_monster(t_data *data, t_dim *dim);
void	set_hearts(t_data *data, t_dim *dim, int count);
void	set_table(t_data *data);
void	set_number(t_data *data, int i, int x);
void	set_gun(t_data *data, t_dim *dim);
void	set_flame(t_data *data, t_dim *dim);

void	create_flow_tab(t_data *data, void **tab);
void	create_number_tab(t_data *data, void **tab);
void	create_gun_left_tab(t_data *data, void **tab);
void	create_gun_right_tab(t_data *data, void **tab);
void	create_other_tab(t_data *data, void **tab);

void	errors(t_data data, char *line);
void	check_wall(char *line);
void	check_error_name(char *argv);
void	ft_destroy_all(t_data *data);

void	ft_exit(char *line, char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
int		find_position(char *line, char c);

#endif
