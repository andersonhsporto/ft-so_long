#include "../includes/so_long.h"

int	key_check(int keycode, t_game *parameter)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(parameter->mlx, parameter->window_pointer);
		printf("\n EXIT \n\n");
		exit(0);
	}
	if (keycode == LEFT)
	{
		parameter->left = 1;
	}
	if (keycode == RIGHT)
	{
		parameter->vector.x += parameter->vector.x;
	}
	if (keycode == UP)
		parameter->up = 1;
	if (keycode == DOWN)
		parameter->down = 1;
	mlx_put_image_to_window(parameter->mlx, parameter->window_pointer,
		parameter->img.pointer, parameter->vector.x, parameter->vector.y);
	printf("Key: %d\n", keycode);
	return (0);
}