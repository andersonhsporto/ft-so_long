/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_left_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:56:29 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/17 17:59:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	check_left(t_game *game)
{
	if ((game->character.x > 32))
	{
		if (!(game->plot.map[(game->character.y / 32)]
				[((game->character.x - 32) / 32)] == '1'))
		{
			game->character.x -= 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_left(t_game *game)
{
	check_left(game);
	game->character.mem = 2;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_l.ptr, game->character.x, game->character.y);
	return ;
}
