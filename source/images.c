#include "../includes/so_long.h"

void init_images(t_game	*game)
{
	game->wall = new_sprite(game->mlx_pointer, "./img/tree50.xpm");
	game->floor = new_sprite(game->mlx_pointer, "./img/c50.xpm");
	game->collect = new_sprite(game->mlx_pointer, "./img/potion.xpm");
	game->portal = new_sprite(game->mlx_pointer, "./img/p1.xpm");
	game->character = new_sprite(game->mlx_pointer, "./img/link_sprites/down_1__.xpm");
	game->character_l = new_sprite(game->mlx_pointer, "./img/link_sprites/left_1__.xpm");
	game->character_r = new_sprite(game->mlx_pointer, "./img/link_sprites/right_1__.xpm");
	game->character_u = new_sprite(game->mlx_pointer, "./img/link_sprites/up_1__.xpm");
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	img.pixels	= (int *)mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
	mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
	mlx_destroy_window(game->mlx_pointer, game->window_pointer);
	mlx_destroy_display(game->mlx_pointer);
	free_map(game);
	free(game->mlx_pointer);
	return ;
}

void	free_map(t_game	*game)
{
	int i;

	i = 0;
	while (game->plot.map[i] != 0)
	{
		free(game->plot.map[i]);
		game->plot.map[i] = NULL;
		i++;
	}
	free(game->plot.map);
	return ;
}

void	print_error(char *message, t_game *game, int i)
{
	if (i == 0)
	{
		destroy_image(game);
		exit(0);
		return ;
	}
	printf("Error\n%s\n", message);
	exit(1);
	return ;
}