#include "./includes/so_long.h"

void	init_so_long(t_game *teste)
{
	teste->mlx = mlx_init();
	teste->window_pointer = mlx_new_window(teste->mlx, 640, 360, "so_long");
}

int	main(void)
{
	t_game	game;

	init_so_long(&game);
	mlx_loop(game.mlx);
}
