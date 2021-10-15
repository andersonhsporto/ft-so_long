#include "../../includes/so_long.h"

static void	check_left(t_game *game)
{
	if ((game->character.x > 32))
	{
		if (!(game->plot.map[(game->character.y / 32)]
				[((game->character.x - 32) / 32)] == '1'))
		{
			game->character.x -= 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_left(t_game *game)
{
	if (game->i.collectible == 1 && (game->plot.map[(game->character.y / 32)]
			[((game->character.x - 32) / 32)] == 'C'))
	{
		game->character.x -= 32;
		map_maker(game);
		print_moves(game);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_l.ptr, game->character.x, game->character.y);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (game->portal.x), (game->portal.y));
		return ;
	}
	check_left(game);
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_l.ptr, game->character.x, game->character.y);
	return ;
}
