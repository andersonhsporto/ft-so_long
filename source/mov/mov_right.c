#include "../../includes/so_long.h"

static void	check_right(t_game *game)
{
	if (game->character.x < ((game->plot.length * 32) - 64))
	{
		if (!(game->plot.map[(game->character.y / 32)]
				[((game->character.x + 32) / 32)] == '1'))
		{
			game->character.x += 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_right(t_game *game)
{
	if (game->i.collectible == 1 && (game->plot.map[(game->character.y / 32)]
			[((game->character.x + 32) / 32)] == 'C'))
	{
		game->character.x += 32;
		map_maker(game);
		print_moves(game);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_r.ptr, game->character.x, game->character.y);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (game->portal.x), (game->portal.y));
		return ;
	}
	check_right(game);
	game->character.mem = 3;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_r.ptr, game->character.x, game->character.y);
	return ;
}
