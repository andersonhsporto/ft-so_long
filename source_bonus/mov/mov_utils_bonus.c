/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/17 14:59:11 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static int	check_win(t_game *game)
{
	if ((game->plot.map[game->character.y / 32][game->character.x / 32] == 'E')
		&& game->i.collectible == 0 && (game->plot.map[game->character.y / 32]
		[((game->character.x + 30) / 32)] == 'E' ))
		return (1);
	else if (((game->plot.map[(game->character.y + 16) / 32]
				[game->character.x / 32] == 'E') && game->i.collectible == 0
			&& (game->plot.map[(game->character.y + 16) / 32]
				[((game->character.x + 30) / 32)] == 'E' )))
		return (1);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->character.y / 32][(game->character.x) / 32] == 'C')
	{
		game->plot.map[game->character.y / 32][game->character.x / 32] = '0';
		game->i.collectible--;
	}
	else if (game->plot.map[game->character.y / 32]
		[((game->character.x + 30) / 32)] == 'C' )
	{
		game->plot.map[game->character.y / 32]
		[((game->character.x + 30) / 32)] = '0';
		game->i.collectible--;
	}
	else if (((ft_strchr("fF", game->plot.map[game->character.y / 32]
					[(game->character.x + 31) / 32]))) || (ft_strchr
			("fF", game->plot.map [game->character.y / 32]
				[(game->character.x) / 32])))
	{
		endgame(RED"\n\nThe End! you died :( "ENDC, game, -1);
	}
	else if (check_win(game))
		endgame(GREEN"\n\nThe End! :) "ENDC, game, -1);
	return ;
}
