#include "../../includes/so_long_bonus.h"

int	key_check(int keycode, t_game *parameter)
{
	if (keycode == ESC)
		endgame("", parameter, -1);
		//destroy_image(parameter);
	if (keycode == LEFT)
		move_left(parameter);
	if (keycode == RIGHT)
		move_right(parameter);
	if (keycode == UP)
		move_up(parameter);
	if (keycode == DOWN)
		move_down(parameter);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->character.y / 32][game->character.x / 32] == 'C')
	{
		game->plot.map[game->character.y / 32][game->character.x / 32] = '0';
		game->i.collectible--;
	}
	if (game->plot.map[game->character.y / 32][game->character.x / 32] == 'E' && game->i.collectible == 0)
	{
		endgame("\n\nThe End! :) \n", game, -1);
	}
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
	return ;
}
