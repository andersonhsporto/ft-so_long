#include "../../includes/so_long.h"

void	print_moves(t_game *game)
{
	//game->i.movements += 1;
	if (game->plot.map[game->character.y / 32][game->character.x / 32] == 'C')
	{
		game->plot.map[game->character.y / 32][game->character.x / 32] = '0';
		game->i.collectible--;
	}

	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->character.movements, 1);
	//printf("Movements: %d\n", ++game->i.movements);
	//printf("Movements: %d\n", game->i.collectible);
	//printf("%i\n", game->portal.pixels);
	return ;
}
