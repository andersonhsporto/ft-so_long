#include "../../includes/so_long.h"

static void	check_down(t_game *game)
{
	if (game->character.y < ((game->plot.height * 32) - 64))
	{
		if (!(game->plot.map[((game->character.y + 32)
						/ 32)][(game->character.x / 32)] == '1'))
		{
			game->character.y += 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_down(t_game *game)
{
	if (game->i.collectible == 1 && (game->plot.map[((game->character.y + 32)
						/ 32)][(game->character.x / 32)] == 'C'))
	{
		game->character.y += 32;
		map_maker(game);
		print_moves(game);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character.ptr, game->character.x, game->character.y);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (game->portal.x), (game->portal.y));
		return ;
	}
	check_down(game);
	game->character.mem = 1;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character.ptr, game->character.x, game->character.y);
	return ;
}

