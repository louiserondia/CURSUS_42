
	mlx_put_image_to_window(data.mlx, data.win, data.tree, 256, 256);
	mlx_put_image_to_window(data.mlx, data.win, data.tree, 768, 128);










	images_init(&data);

	void	images_init(t_data *data)
{
	int	width;
	int	height;
	int	x;
	int	y;

	data->snow_path = "sprites/big_snow_big.xpm";
	data->tree_path = "sprites/tree_2_big.xpm";
	data->wood_path = "sprites/wood_2_big.xpm";
	data->me_path = "sprites/me_small.xpm";
	data->snow = mlx_xpm_file_to_image(data->mlx, data->snow_path, &width, &height);
	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->snow, x * 128, y * 128);
			x++;
		}
		y++;
	}
	data->tree = mlx_xpm_file_to_image(data->mlx, data->tree_path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->tree, 512, 512);
	data->wood = mlx_xpm_file_to_image(data->mlx, data->wood_path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->wood, 578, 578);
	data->me =  mlx_xpm_file_to_image(data->mlx, data->me_path, &width, &height);
	data->x_me = 0;
	data->y_me = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->me, data->x_me, data->y_me);
}










	
		if (data->line[i - 1] == 'E')
			exit (1);
		data->line[i] = '0';
		data->line[i - 1] = 'P';
		mlx_clear_window(data->mlx, data->win);
		read_map(data, &data->dim, data->line);



// void    count_horizontal(char *line)
// {
//     int    i;
//     int    j;
//     int    old;

//     i = 0;
//     j = 0;
//     old = 0;
//     while (line[old] != '\n')
//         old++;
//     while (line[i])
//     {
//         j = ft_strchrlen(line + i, '\n');
//         i += j + 1;
//         if (j != old)
//         {
//             free (line);
//             ft_printf("j %d\n", j);
//             ft_printf("old %d\n", old);
//             ft_exit("Error\nIncorrect map\n");
//         }
//         ft_printf("line + i %s\n", line + i);
//     }
//     if (line[i] == '\0' && (j != old || line[i - 1] == '\n'))
//     {
//         free (line);
//         ft_exit("Error\nIncorrect map\n");
//     }
// }




typedef struct s_flow
{
    int        flow_count;
    int        heart_count;
    int        max;
    void    *flow0_heart1;
    char    *flow0_heart1_path;
    void    *flow0_heart2;
    char    *flow0_heart2_path;
    void    *flow0_heart3;
    char    *flow0_heart3_path;
    
    void    *flow1_heart1;
    char    *flow1_heart1_path;
    void    *flow1_heart2;
    char    *flow1_heart2_path;
    void    *flow1_heart3;
    char    *flow1_heart3_path;
    
    void    *flow2_heart1;
    char    *flow2_heart1_path;
    void    *flow2_heart2;
    char    *flow2_heart2_path;
    void    *flow2_heart3;
    char    *flow2_heart3_path;
    
    void    *flow3_heart1;
    char    *flow3_heart1_path;
    void    *flow3_heart2;
    char    *flow3_heart2_path;
    void    *flow3_heart3;
    char    *flow3_heart3_path;
    
    void    *flow4_heart1;
    char    *flow4_heart1_path;
    void    *flow4_heart2;
    char    *flow4_heart2_path;
    void    *flow4_heart3;
    char    *flow4_heart3_path;
}    t_flow;



void    read_me_in_file(t_data *data)
{
    int    width;
    int    height;
    
    data->flow.flow0_heart1 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow0_heart1_path, &width, &height);
    data->flow.flow0_heart2 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow0_heart2_path, &width, &height);
    data->flow.flow0_heart3 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow0_heart3_path, &width, &height);
    
    data->flow.flow1_heart1 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow1_heart1_path, &width, &height);
    data->flow.flow1_heart2 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow1_heart2_path, &width, &height);
    data->flow.flow1_heart3 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow1_heart3_path, &width, &height);
    
    data->flow.flow2_heart1 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow2_heart1_path, &width, &height);
    data->flow.flow2_heart2 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow2_heart2_path, &width, &height);
    data->flow.flow2_heart3 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow2_heart3_path, &width, &height);
    
    data->flow.flow3_heart1 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow3_heart1_path, &width, &height);
    data->flow.flow3_heart2 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow3_heart2_path, &width, &height);
    data->flow.flow3_heart3 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow3_heart3_path, &width, &height);
    
    data->flow.flow4_heart1 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow4_heart1_path, &width, &height);
    data->flow.flow4_heart2 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow4_heart2_path, &width, &height);
    data->flow.flow4_heart3 = mlx_xpm_file_to_image(data->mlx,
                                                    data->flow.flow4_heart3_path, &width, &height);
}




data->img.me_path = "sprites/me_small.xpm";




void    set_character(t_data *data, t_dim *dim)
{
    if (data->flow.flow_count == 0)
    {
        if (data->flow.heart_count == 1)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0_heart1,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 2)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0_heart2,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 3)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow0_heart3,
                                    dim->x, dim->y);
    }
    else if (data->flow.flow_count == 1)
    {
        if (data->flow.heart_count == 1)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1_heart1,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 2)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1_heart2,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 3)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1_heart3,
                                    dim->x, dim->y);
    }
    else if (data->flow.flow_count == 2)
    {
        if (data->flow.heart_count == 1)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2_heart1,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 2)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2_heart2,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 3)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2_heart3,
                                    dim->x, dim->y);
    }
    else if (data->flow.flow_count == 3)
    {
        if (data->flow.heart_count == 1)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3_heart1,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 2)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3_heart2,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 3)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3_heart3,
                                    dim->x, dim->y);
    }
    else if (data->flow.flow_count >= 4)
    {
        if (data->flow.heart_count == 1)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4_heart1,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 2)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4_heart2,
                                    dim->x, dim->y);
        else if (data->flow.heart_count == 3)
            mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4_heart3,
                                    dim->x, dim->y);
    }
}



void    set_number(t_data *data, t_dim *dim)
{
    (void) dim;
    void    *tab[10];
    int    i;
    int    dozen;
    
    create_tab(data, tab);
    i = data->operations;
    mlx_put_image_to_window(data->mlx, data->win, data->number.table,
                            64, 32);
    if (i < 10)
        mlx_put_image_to_window(data->mlx, data->win, tab[i],
                                64, 32);
    else if (i >= 10 &&  i < 100)
    {
        dozen = i / 10;
        i = i % 10;
        mlx_put_image_to_window(data->mlx, data->win, tab[i],
                                64, 32);
        mlx_put_image_to_window(data->mlx, data->win, tab[dozen],
                                48, 32);
    }
}






int    animate_gun(t_data *data)
{
    get_coordinates(data);
    if (data->gun.time >= 1)
    {
        data->gun.time++;
        if (data->gun.time < 3)
            data->gun.gun_nb = 6;
        else if (data->gun.time < 6)
            data->gun.gun_nb = 5;
        else if (data->gun.time < 9)
            data->gun.gun_nb = 4;
        else if (data->gun.time < 12)
            data->gun.gun_nb = 3;
        else if (data->gun.time < 15)
            data->gun.gun_nb = 2;
        else if (data->gun.time < 18)
            data->gun.gun_nb = 1;
        
        else if (data->gun.time < 36)
            data->gun.gun_nb = 0;
        else if (data->gun.time < 39)
            data->gun.gun_nb = 1;
        else if (data->gun.time < 42)
            data->gun.gun_nb = 2;
        else if (data->gun.time < 45)
            data->gun.gun_nb = 3;
        else if (data->gun.time < 48)
            data->gun.gun_nb = 4;
        else if (data->gun.time < 51)
            data->gun.gun_nb = 5;
        else if (data->gun.time < 60)
            data->gun.gun_nb = 6;
        else if (data->gun.time > 54)
        {
            data->gun.time = 0;
            data->gun.gun_nb = 0;
        }
        mlx_clear_window(data->mlx, data->win);
        read_map(data, &data->dim, data->line);
        return (1);
    }
    else
        return (0);
}




ft_printf("me : %d\n", me);
ft_printf("monster : %d\n", monster);
ft_printf("max_x : %d\n", data->dim.max_x);
ft_printf("y : %d\n", y);









void    set_character_1flow(t_data *data, t_dim *dim)
{
    mlx_put_image_to_window(data->mlx, data->win, data->flow.flow1,
                            dim->x, dim->y);
    set_hearts(data, dim, data->heart.count_me);
}

void    set_character_2flow(t_data *data, t_dim *dim)
{
    mlx_put_image_to_window(data->mlx, data->win, data->flow.flow2,
                            dim->x, dim->y);
    set_hearts(data, dim, data->heart.count_me);
}
void    set_character_3flow(t_data *data, t_dim *dim)
{
    mlx_put_image_to_window(data->mlx, data->win, data->flow.flow3,
                            dim->x, dim->y);
    set_hearts(data, dim, data->heart.count_me);
}

void    set_character_4flow(t_data *data, t_dim *dim)
{
    mlx_put_image_to_window(data->mlx, data->win, data->flow.flow4,
                            dim->x, dim->y);
    set_hearts(data, dim, data->heart.count_me);
}







        set_monster_left(data, dim);


void    set_monster_left(t_data *data, t_dim *dim)
{
    mlx_put_image_to_window(data->mlx, data->win, data->monster.chimere_left,
                            dim->x, dim->y);
    set_hearts(data, dim, data->heart.count_monster);
}










void    init_sprites(t_data *data)
{
    data->img.snow_path = "sprites/big_snow_big.xpm";
    data->img.tree_path = "sprites/tree.xpm";
    data->img.brieuc_path = "sprites/brieuc.xpm";
    data->img.flower_path = "sprites/flower.xpm";
    
    data->monster.chimere_left_path = "sprites/chimere_knife_2.xpm";
    data->monster.chimere_right_path = "sprites/chimere_right.xpm";
    
    // data->flow.flow0_path = "sprites/flow/me_0flow.xpm";
    data->flow.flow1_path = ;
    data->flow.flow2_path = "sprites/flow/me_2flow.xpm";
    data->flow.flow3_path = "sprites/flow/me_3flow.xpm";
    data->flow.flow4_path = "sprites/flow/me_4flow.xpm";
    
    data->heart.heart1_path = ;
    data->heart.heart2_path = "sprites/heart/2heart.xpm";
    data->heart.heart3_path = "sprites/heart/3heart.xpm";
    
    data->number.table_path = ;
    data->number.zero_path = ;
    data->number.one_path = "sprites/number/1.xpm";
    data->number.two_path = "sprites/number/2.xpm";
    data->number.three_path = "sprites/number/3.xpm";
    data->number.four_path = "sprites/number/4.xpm";
    data->number.five_path = "sprites/number/5.xpm";
    data->number.six_path = "sprites/number/6.xpm";
    data->number.seven_path = "sprites/number/7.xpm";
    data->number.eight_path = "sprites/number/8.xpm";
    data->number.nine_path = "sprites/number/9.xpm";
    
    data->gun.left1_path = "sprites/gun/gun_1.xpm";
    data->gun.left2_path = "sprites/gun/gun_2.xpm";
    data->gun.left3_path = "sprites/gun/gun_3.xpm";
    data->gun.left4_path = "sprites/gun/gun_4.xpm";
    data->gun.left5_path = "sprites/gun/gun_5.xpm";
    data->gun.left6_path = "sprites/gun/gun_6.xpm";
    data->gun.left7_path = "sprites/gun/gun_7.xpm";
    data->gun.flame_left_path = "sprites/gun/flame.xpm";
    
    data->gun.right1_path = ;
    data->gun.right2_path = "sprites/gun/gun_2_right.xpm";
    data->gun.right3_path = "sprites/gun/gun_3_right.xpm";
    data->gun.right4_path = "sprites/gun/gun_4_right.xpm";
    data->gun.right5_path = "sprites/gun/gun_5_right.xpm";
    data->gun.right6_path = "sprites/gun/gun_6_right.xpm";
    data->gun.right7_path = "sprites/gun/gun_7_right.xpm";
    data->gun.flame_right_path = "sprites/gun/flame_right.xpm";
    
    read_in_file(data);
    read_flow_in_file(data);
    read_heart_in_file(data);
    read_number_in_file(data);
    read_gun_left_in_file(data);
    read_gun_right_in_file(data);
}












// void    compare_horizontal(t_data *data, char *line, int *i, int *j, int max)
// {
//     *j = 0;
//     while (line[*i] && line[*i] != '\n')
//     {
//         (*i)++;
//         (*j)++;
//     }
//     if (line[*i] == '\n' && (*j) != max)
//         ft_exit(data, "Error\nIncorrect map\n");
//     else if (line[*i] == '\n' && (*j) == max)
//         (*i)++;
// }






