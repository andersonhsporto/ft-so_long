#include "../../includes/so_long.h"

static void	check_down(t_game *game)
{
	if (game->character.y < ((game->plot.height * 32) - 64))
	{
		game->character.y += 2;
		print_moves(game);
	}
	return ;
}

static void	print_down(t_game *game, int image_number)
{
	void	*image;

	if (image_number == 1)
		image = game->character.ptr;
	if (image_number == 2)
		image = game->character_d2.ptr;
	check_down(game);
	map_maker(game);
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		image, game->character.x, game->character.y);
	return ;
}

void	move_down(t_game *game)
{
	static int i;

	if (!i)
		i = 0;
	if (i == 2)
	{
		print_down(game, 1);
		i = 0;
	}
	else
	{
		print_down(game, 2);
		i++;
	}
	return ;
}
