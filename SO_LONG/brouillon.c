
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


