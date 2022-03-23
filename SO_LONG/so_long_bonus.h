/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/23 17:37:53 by lrondia          ###   ########.fr       */
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

// typedef struct s_flow
// {
// 	int		count;
// 	int		max;
// 	void	*me_1flower;
// 	char	*me_1flower_path;
// 	void	*me_2flower;
// 	char	*me_2flower_path;
// 	void	*me_3flower;
// 	char	*me_3flower_path;
// 	void	*me_4flower;
// 	char	*me_4flower_path;
// }	t_flow;

typedef struct s_flow
{
	int		flow_count;
	int		heart_count;
	int		max;
	void	*flow0_heart1;
	char	*flow0_heart1_path;
	void	*flow0_heart2;
	char	*flow0_heart2_path;
	void	*flow0_heart3;
	char	*flow0_heart3_path;

	void	*flow1_heart1;
	char	*flow1_heart1_path;
	void	*flow1_heart2;
	char	*flow1_heart2_path;
	void	*flow1_heart3;
	char	*flow1_heart3_path;

	void	*flow2_heart1;
	char	*flow2_heart1_path;
	void	*flow2_heart2;
	char	*flow2_heart2_path;
	void	*flow2_heart3;
	char	*flow2_heart3_path;

	void	*flow3_heart1;
	char	*flow3_heart1_path;
	void	*flow3_heart2;
	char	*flow3_heart2_path;
	void	*flow3_heart3;
	char	*flow3_heart3_path;

	void	*flow4_heart1;
	char	*flow4_heart1_path;
	void	*flow4_heart2;
	char	*flow4_heart2_path;
	void	*flow4_heart3;
	char	*flow4_heart3_path;
}	t_flow;

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
	void	*me;
	char	*me_path;
	void	*chimere;
	char	*chimere_path;
}	t_img;

// typedef struct	s_screen
// {
// 	void	*heart;
// 	char	*heart_path;
// }

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
void	set_monster(t_data *data, t_dim *dimensions);

void	errors(t_data data, char *line);
void	check_wall(char *line);
void	check_error_name(char *argv);

void	ft_exit(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);

#endif
