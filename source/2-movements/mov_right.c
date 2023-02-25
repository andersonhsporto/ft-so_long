/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:56:46 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:47:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool	is_right_wall(t_game *game);
static void	check_right(t_game *game);

void	move_right(t_game *game)
{
	check_right(game);
	game->character.mem = right;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_r.ptr, game->character.x, game->character.y);
	return ;
}

static void	check_right(t_game *game)
{
	if (game->character.x < \
	((game->plot.length * SPRITE_SIZE) - (SPRITE_SIZE * 2)))
	{
		if (!is_right_wall(game))
		{
			game->character.x += SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_right_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[(game->character.y / SPRITE_SIZE)] \
	[((game->character.x + SPRITE_SIZE) / SPRITE_SIZE)] != '1') \
	);
}
