#include "../../includes/so_long.h"

static void	check_left(t_game *parameter)
{
	if ((parameter->character.x > 26))
		parameter->character.x -= 2;
	return ;
}

static void	print_left(t_game *parameter, int image_number)
{
	void	*image;

	if (image_number == 1)
		image = parameter->character_l.ptr;
	if (image_number == 2)
		image = parameter->character_l2.ptr;
	check_left(parameter);
	map_maker(parameter);
	mlx_put_image_to_window(parameter->mlx_pointer, parameter->window_pointer,
		image, parameter->character.x, parameter->character.y);
	return ;
}

void	move_left(t_game *parameter)
{
	static int i;

	if (!i)
		i = 0;
	if (i == 3)
	{
		print_left(parameter, 1);
		i = 0;
	}
	else
	{
		print_left(parameter, 2);
		i++;
	}
	return ;
}
