#include "../../includes/so_long.h"

static void	print_right(t_game *parameter, int image_number)
{
	void	*image;

	if (image_number == 1)
		image = parameter->character_r.ptr;
	if (image_number == 2)
		image = parameter->character_r2.ptr;
	if (!(parameter->character.x > 466))
		parameter->character.x += 2;
	map_maker(parameter);
	mlx_put_image_to_window(parameter->mlx_pointer, parameter->window_pointer,
		image, parameter->character.x, parameter->character.y);
	return ;
}

void	move_right(t_game *parameter)
{
	static int i;

	if (!i)
		i = 0;
	if (i == 3)
	{
		print_right(parameter, 1);
		i = 0;
	}
	else
	{
		print_right(parameter, 2);
		i++;
	}
	return ;
}