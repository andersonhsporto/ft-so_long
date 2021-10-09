#include "../includes/so_long.h"

int	main(void)
{
	t_game	game;

	//if (argc == 2)
	//{
		game.map = "100111110000";
		init_so_long(&game);
		init_images(&game);
		map_maker(&game);
		//mlx_key_hook(game.window_pointer, key_check, &game);
		mlx_hook(game.window_pointer, 2, (1L << 0), key_check, &game);
		mlx_loop(game.mlx_pointer);
	//}
	//else
		//exit(1);
	return (0);
}
