#include "../includes/so_long.h"

int		key_check(int keycode, t_game *parameter)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(parameter->mlx_pointer, parameter->window_pointer);
		printf("\n EXIT \n\n");
		exit(0);
	}
	if (keycode == LEFT)
		parameter->character.x -= 20;
	if (keycode == RIGHT)
		parameter->character.x += 20;
	if (keycode == UP)
		parameter->character.y -= 20;
	if (keycode == DOWN)
		parameter->character.y += 20;
	map_maker(parameter);
	mlx_put_image_to_window(parameter->mlx_pointer, parameter->window_pointer,
		parameter->character.ptr, parameter->character.x, parameter->character.y);
	printf("Key: %d\n", keycode);
	return (0);
}