#include "../../includes/so_long.h"

static void	check_left(t_game *game)
{
	if ((game->character.x > 32))
	{
		if (!(game->plot.map[(game->character.y / 32)]
				[((game->character.x - 32) / 32)] == '1'))
		{
			game->character.x -= 32;
			print_moves(game);
		}
	}
	return ;
}

static void	print_left(t_game *game, int image_number)
{
	void	*image;

	if (image_number == 1)
		image = game->character_l.ptr;
	if (image_number == 2)
		image = game->character_l2.ptr;
	check_left(game);
	map_maker(game);
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		image, game->character.x, game->character.y);
	return ;
}

void	move_left(t_game *game)
{
	static int	i;

	if (!i)
		i = 0;
	if (i == 3)
	{
		print_left(game, 1);
		i = 0;
	}
	else
	{
		print_left(game, 2);
		i++;
	}
	return ;
}
