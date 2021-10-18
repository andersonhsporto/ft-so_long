/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/17 17:59:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	key_check(int keycode, t_game *game)
{
	game->character.mem = 0;
	if (keycode == ESC)
		endgame("", game, -1);
	if (keycode == LEFT)
		move_left(game);
	if (keycode == RIGHT)
		move_right(game);
	if (keycode == UP)
		move_up(game);
	if (keycode == DOWN)
		move_down(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->character.y / 32][game->character.x / 32] == 'C')
	{
		game->plot.map[game->character.y / 32][game->character.x / 32] = '0';
		game->i.collectible--;
	}
	if (game->plot.map[game->character.y / 32]
		[game->character.x / 32] == 'E' && game->i.collectible == 0)
	{
		endgame("\n\nThe End! :) \n", game, -1);
	}
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
	return ;
}
