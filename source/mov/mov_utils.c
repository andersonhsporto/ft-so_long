#include "../../includes/so_long.h"

void	print_moves(t_game *game)
{
	game->character.m += 1;
	//ft_putstr_fd("\rMovements: ", 1);
	//ft_putnbr_fd(game->character.m, 1);
	printf("Movements: %d\n", game->character.m);
	return ;
}
