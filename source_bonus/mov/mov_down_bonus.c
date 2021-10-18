/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_down_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:55:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/18 03:51:45 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	check_down(t_game *game)
{
	if (game->character.y < ((game->plot.height * 32) - 64))
	{
		if (!(game->plot.map[((game->character.y + 32)
						/ 32)][(game->character.x / 32)] == '1'))
		{
			game->character.y += 3;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

int	print_frame_down(t_game *game, int old_counter, int new_counter)
{
	if (old_counter == 0)
	{
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->down_a.frame1, game->character.x, game->character.y);
	}
	if (old_counter == 1)
	{
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->down_a.frame2, game->character.x, game->character.y);
	}
		if (old_counter == 2)
	{
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->down_a.frame3, game->character.x, game->character.y);
	}
	return(new_counter);
}

void	move_down(t_game *game)
{
	static int i;

	game->character.mem = 1;
	check_down(game);
	if (i == 0)
		i = print_frame_down(game, 0, 1);
	else if (i == 1)
		i = print_frame_down(game, 1, 2);
	else if (i == 2)
		i = print_frame_down(game, 2, 0);
	mlx_do_sync(game->mlx_pointer);
	return ;
}
