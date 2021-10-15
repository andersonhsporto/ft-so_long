#include "../includes/so_long.h"

int	key_check(int keycode, t_game *parameter)
{
	if (keycode == ESC)
		print_error("", parameter, 0);
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
