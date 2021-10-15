#include "../../includes/so_long.h"

static void	check_up(t_game *game)
{
	if ((game->character.y > 32))
	{
		if (!(game->plot.map[((game->character.y - 32)
						/ 32)][(game->character.x / 32)] == '1'))
		{
			game->character.y -= 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_up(t_game *game)
{
	if (game->i.collectible == 1 && (game->plot.map[((game->character.y - 32)
						/ 32)][(game->character.x / 32)] == 'C'))
	{
		game->character.y -= 32;
		map_maker(game);
		print_moves(game);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_u.ptr, game->character.x, game->character.y);
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (game->portal.x), (game->portal.y));
		return ;
	}
	check_up(game);
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_u.ptr, game->character.x, game->character.y);
	return ;
}
