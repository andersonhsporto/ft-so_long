/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_right_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:56:46 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/18 20:53:34 by anhigo-s         ###   ########.fr       */
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


int	print_frame_right(t_game *game, int old_counter, int new_counter)
{
	if (old_counter == 0)
		put_image(game, game->right_a.frame0);
	if (old_counter == 2)
		put_image(game, game->right_a.frame1);
	if (old_counter == 4)
		put_image(game, game->right_a.frame2);
	if (old_counter == 6)
		put_image(game, game->right_a.frame3);
	if (old_counter == 8)
		put_image(game, game->right_a.frame4);
	if (old_counter == 10)
		put_image(game, game->right_a.frame5);
	if (old_counter == 12)
		put_image(game, game->right_a.frame6);
	if (old_counter == 14)
		put_image(game, game->right_a.frame7);
	if (old_counter == 16)
		put_image(game, game->right_a.frame8);
	if (old_counter == 18)
		put_image(game, game->right_a.frame9);
	return (new_counter);
}

void	move_right(t_game *game)
{
	check_right(game);
	game->character.mem = 3;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_r.ptr, game->character.x, game->character.y);
	return ;
}
