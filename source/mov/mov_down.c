#include "../../includes/so_long.h"

static void	check_down(t_game *parameter)
{
	if (parameter->character.y < ((parameter->plot.height * 32) - 64))
		parameter->character.y += 2;
	return ;
}

static void	print_down(t_game *parameter, int image_number)
{
	void	*image;

	if (image_number == 1)
		image = parameter->character.ptr;
	if (image_number == 2)
		image = parameter->character_d2.ptr;
	check_down(parameter);
	map_maker(parameter);
	mlx_put_image_to_window(parameter->mlx_pointer, parameter->window_pointer,
		image, parameter->character.x, parameter->character.y);
	return ;
}

void	move_down(t_game *parameter)
{
	static int i;

	if (!i)
		i = 0;
	if (i == 2)
	{
		print_down(parameter, 1);
		i = 0;
	}
	else
	{
		print_down(parameter, 2);
		i++;
	}
	return ;
}
