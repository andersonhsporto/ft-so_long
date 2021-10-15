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
		print_error("Can't open file. The format is not supported!", &game, 1);
	}
	if (argc > 2)
	{
		print_error("Can't open multiple files!", &game, 1);
		//printf("Error\nCan't open multiple files!\n");
		//exit(1);
	}
	else
	{
		print_error("Please specify file name!", &game, 1);
		//printf("Error\nPlease specify file name!\n");
		//exit(1);
	}
	return (0);
}
