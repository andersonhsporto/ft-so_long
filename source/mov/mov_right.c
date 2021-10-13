#include "../../includes/so_long.h"

static void	check_right(t_game *game)
{
	if (game->character.x < ((game->plot.length * 32) - 64))
	{
		if (!(game->plot.map[(game->character.y / 32)]
				[((game->character.x + 32) / 32)] == '1'))
		{
			game->character.x += 32;
			print_moves(game);
		}
	}
	return ;
}

static void	print_right(t_game *game, int image_number)
{
	void	*image;

	if (image_number == 1)
		image = game->character_r.ptr;
	if (image_number == 2)
		image = game->character_r2.ptr;
	check_right(game);
	map_maker(game);
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		image, game->character.x, game->character.y);
	return ;
}

void	move_right(t_game *game)
{
	static int	i;

	if (!i)
		i = 0;
	if (i == 3)
	{
		print_right(game, 1);
		i = 0;
	}
	else
	{
		print_right(game, 2);
		i++;
	}
	return ;
}
