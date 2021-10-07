#include "../includes/so_long.h"

void init_images(t_game	*game)
{
	game->wall = ft_new_sprite(game->mlx_pointer, "./img/tree50.xpm");
	game->floor = ft_new_sprite(game->mlx_pointer, "./img/c50.xpm");
	game->character = ft_new_sprite(game->mlx_pointer, "./img/zelda4.xpm");
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