/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/21 21:23:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_up(t_game *game)
{
	if ((game->character.y > 32))
	{
		if (!(game->plot.map[((game->character.y - 32)
						/ 32)][(game->character.x / 32)] == '1'))
		{
			game->character.y -= 32;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_up(t_game *game)
{
	check_up(game);
	game->character.mem = up;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_u.ptr, game->character.x, game->character.y);
	return ;
}
