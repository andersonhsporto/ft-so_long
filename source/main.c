#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_map(&game, argv[1]);
		init_so_long(&game);
		init_images(&game);
		map_maker(&game);
		player_init(&game);
		//mlx_key_hook(game.window_pointer, key_check, &game);
		mlx_hook(game.window_pointer, 2, (1L << 0), key_check, &game);
		mlx_loop(game.mlx_pointer);
	}
	else
	{
		//perror("teste sem argc");
		exit(1);
	}
	return (0);
}
