/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_right_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:56:46 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/17 17:59:06 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	check_right(t_game *game)
{
	if (game->character.x < ((game->plot.length * 32) - 64))
	{
		if (!(game->plot.map[(game->character.y / 32)]
				[((game->character.x + 32) / 32)] == '1'))
		{
			game->character.x += 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_right(t_game *game)
{
	check_right(game);
	game->character.mem = 3;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_r.ptr, game->character.x, game->character.y);
	return ;
}
