/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/31 18:15:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	read_me_in_file(t_data *data)
{
	int	width;
	int	height;

	data->flow.flow0 = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_0flow.xpm", &width, &height);
	data->flow.flow1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_1flow.xpm", &width, &height);
	data->flow.flow2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_2flow.xpm", &width, &height);
	data->flow.flow3 = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_3flow.xpm", &width, &height);
	data->flow.flow4 = mlx_xpm_file_to_image(data->mlx,
			"sprites/flow/me_4flow.xpm", &width, &height);
	data->heart.heart1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/heart/1heart.xpm", &width, &height);
	data->heart.heart2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/heart/2heart.xpm", &width, &height);
	data->heart.heart3 = mlx_xpm_file_to_image(data->mlx,
			"sprites/heart/3heart.xpm", &width, &height);
}

void	read_number_in_file(t_data *data)
{
	int	width;
	int	height;

	data->number.table = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/table.xpm", &width, &height);
	data->number.zero = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/0.xpm", &width, &height);
	data->number.one = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/1.xpm", &width, &height);
	data->number.two = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/2.xpm", &width, &height);
	data->number.three = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/3.xpm", &width, &height);
	data->number.four = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/4.xpm", &width, &height);
	data->number.five = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/5.xpm", &width, &height);
	data->number.six = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/6.xpm", &width, &height);
	data->number.seven = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/7.xpm", &width, &height);
	data->number.eight = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/8.xpm", &width, &height);
	data->number.nine = mlx_xpm_file_to_image(data->mlx,
			"sprites/number/9.xpm", &width, &height);
}

void	read_gun_left_in_file(t_data *data)
{
	int	width;
	int	height;

	data->gun.left0 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_0.xpm", &width, &height);
	data->gun.left1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_1.xpm", &width, &height);
	data->gun.left2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_2.xpm", &width, &height);
	data->gun.left3 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_3.xpm", &width, &height);
	data->gun.left4 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_4.xpm", &width, &height);
	data->gun.left5 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_5.xpm", &width, &height);
	data->gun.left6 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_left_6.xpm", &width, &height);
	data->gun.flame_left = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/flame_left.xpm", &width, &height);
}

void	read_gun_right_in_file(t_data *data)
{
	int	width;
	int	height;

	data->gun.right0 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_0.xpm", &width, &height);
	data->gun.right1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_1.xpm", &width, &height);
	data->gun.right2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_2.xpm", &width, &height);
	data->gun.right3 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_3.xpm", &width, &height);
	data->gun.right4 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_4.xpm", &width, &height);
	data->gun.right5 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_5.xpm", &width, &height);
	data->gun.right6 = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/gun_right_6.xpm", &width, &height);
	data->gun.flame_right = mlx_xpm_file_to_image(data->mlx,
			"sprites/gun/flame_right.xpm", &width, &height);
}

void	init_sprites(t_data *data)
{
	int	width;
	int	height;

	data->img.snow = mlx_xpm_file_to_image(data->mlx,
			"sprites/snow_new.xpm", &width, &height);
	data->img.tree = mlx_xpm_file_to_image(data->mlx,
			"sprites/tree.xpm", &width, &height);
	data->img.brieuc = mlx_xpm_file_to_image(data->mlx,
			"sprites/brieuc.xpm", &width, &height);
	data->img.brieuc_happy = mlx_xpm_file_to_image(data->mlx,
			"sprites/brieuc_happy.xpm", &width, &height);
	data->img.flower = mlx_xpm_file_to_image(data->mlx,
			"sprites/flower.xpm", &width, &height);
	data->monster.chimere_left = mlx_xpm_file_to_image(data->mlx,
			"sprites/chimere_left.xpm", &width, &height);
	data->monster.chimere_right = mlx_xpm_file_to_image(data->mlx,
			"sprites/chimere_right.xpm", &width, &height);
	read_me_in_file(data);
	read_number_in_file(data);
	read_gun_left_in_file(data);
	read_gun_right_in_file(data);
}
