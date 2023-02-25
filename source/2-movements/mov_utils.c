/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 03:22:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->character.mem = 0;
	if (keycode == ESC)
		endgame("", game, event_ending);
	else if (keycode == LEFT)
		move_left(game);
	else if (keycode == RIGHT)
		move_right(game);
	else if (keycode == UP)
		move_up(game);
	else if (keycode == DOWN)
		move_down(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->character.y / SPRITE_SIZE] \
	[game->character.x / SPRITE_SIZE] == 'C')
	{
		game->plot.map[game->character.y / SPRITE_SIZE] \
		[game->character.x / SPRITE_SIZE] = '0';
		game->i.collectible--;
	}
	else if (game->plot.map[game->character.y / SPRITE_SIZE]
		[game->character.x / SPRITE_SIZE] == 'E' && game->i.collectible == 0)
	{
		endgame(GREEN"\n\nThe End! :)"ENDC, game, game_over);
	}
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
	return ;
}
