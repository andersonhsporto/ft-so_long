/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:56:29 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:42:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool	is_left_wall(t_game *game);
static void	check_left(t_game *game);

void	move_left(t_game *game)
{
	check_left(game);
	game->character.mem = left;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_l.ptr, game->character.x, game->character.y);
	return ;
}

static void	check_left(t_game *game)
{
	if ((game->character.x > SPRITE_SIZE))
	{
		if (!is_left_wall(game))
		{
			game->character.x -= SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_left_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[(game->character.y / SPRITE_SIZE)] \
	[((game->character.x - SPRITE_SIZE) / SPRITE_SIZE)] != '1') \
	);
}
