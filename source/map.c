#include "../includes/so_long.h"

void	map_maker(t_game	*game)
{
	int i;

	i = 0;
	while(game->map[i])
	{
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->floor.ptr,  (50 * i), 0);
		else
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->wall.ptr,  (50 * i), 0);
		i++;
	}
	return ;
}