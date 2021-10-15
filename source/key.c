#include "../includes/so_long.h"

int	key_check(int keycode, t_game *parameter)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(parameter->mlx_pointer, parameter->window_pointer);
		exit(1);
	}
	if (keycode == LEFT)
		move_left(parameter);
	if (keycode == RIGHT)
		move_right(parameter);
	if (keycode == UP)
		move_up(parameter);
	if (keycode == DOWN)
		move_down(parameter);
	//printf("y = %i x = %i\n", parameter->character.y, parameter->character.x);
	return (0);
}
