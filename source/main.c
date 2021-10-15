#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;


	if (argc == 2 && (check_arg(argv[1])))
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
	if ((argc == 2 && !(check_arg(argv[1]))))
	{
		printf("Error\nCan't open file. The format is not supported!\n");
		exit(1);
	}
	if (argc > 2)
	{
		printf("Error\nCan't open multiple files!\n");
		exit(1);
	}
	else
	{
		printf("Error\nPlease specify file name!\n");
		exit(1);
	}
	return (0);
}
