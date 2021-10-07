#include "../includes/so_long.h"

int	main(void)
{
	t_game	game;
	int i;

	game.map = "100111110000";

	i = 0;
	init_so_long(&game);
	init_images(&game);
	map_maker(&game);
	mlx_key_hook(game.window_pointer, key_check, &game);
	mlx_loop(game.mlx_pointer);
	return (0);
}
