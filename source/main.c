#include "../includes/so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.vector.x, &img.vector.y);
	img.pixels  = mlx_get_data_addr(img.pointer,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}


int	main(void)
{
	t_game	game;
	t_image zelda;
	t_image parede;
	int i;

	game.map = "100111110000";
	init_so_long(&game);

	zelda = ft_new_sprite(game.mlx, "./img/tree50.xpm");
	parede = ft_new_sprite(game.mlx, "./img/c50.xpm");
	game.img = ft_new_sprite(game.mlx, "./img/zelda3.xpm");
	i = 0;
	mlx_put_image_to_window(game.mlx, game.window_pointer, zelda.pointer,  (1), 1);
	while(game.map[i])
	{
		if (game.map[i] == '1')
			mlx_put_image_to_window(game.mlx, game.window_pointer, zelda.pointer,  (50 * i), 0);
		else
			mlx_put_image_to_window(game.mlx, game.window_pointer, parede.pointer,  (50 * i), 0);
		i++;
	}
	mlx_key_hook(game.window_pointer, key_check, &game);
	mlx_loop(game.mlx);
	return (0);
}
