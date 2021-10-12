#include "../includes/so_long.h"

void init_images(t_game	*game)
{
	game->wall = ft_new_sprite(game->mlx_pointer, "./img/tree50.xpm");
	game->floor = ft_new_sprite(game->mlx_pointer, "./img/c50.xpm");
	game->collect = ft_new_sprite(game->mlx_pointer, "./img/potion.xpm");
	game->character = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/down_1__.xpm");
	game->character_d2 = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/down_3__.xpm");
	game->character_l = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/left_1__.xpm");
	game->character_l2 = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/left_new32.xpm");
	game->character_l3 = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/left_2__.xpm"); //extra
	game->character_r = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/right_1__.xpm");
	game->character_r2 = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/right_new32.xpm");
	game->character_u = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/up_1__.xpm");
	game->character_u2 = ft_new_sprite(game->mlx_pointer, "./img/link_sprites/up_2__.xpm");
	return ;
}

t_img	ft_new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	img.pixels	= mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	free (game->floor.ptr);
	free (game->character.ptr);
	free (game->character_d2.ptr);
	free (game->character_l.ptr);
	free (game->character_l2.ptr);
	free (game->character_l3.ptr);
	free (game->character_r.ptr);
	free (game->character_r2.ptr);
	free (game->character_u.ptr);
	free (game->character_u2.ptr);
	return ;
}