/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_up_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/19 01:41:21 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	check_up(t_game *game)
{
	if ((game->character.y > 32))
	{
		if ((!(game->plot.map[((game->character.y - 4) / 32)]
					[(game->character.x / 32)] == '1')) && (
				!(game->plot.map[((game->character.y - 4) / 32)]
					[((game->character.x + 31) / 32)] == '1')))
		{
			game->character.y -= 4;
			map_maker(game);
			print_moves(game);
		}
	}
	return ;
}

int	print_frame_up(t_game *game, int old_counter, int new_counter)
{
	if (old_counter == 0)
		put_image(game, game->up_a.frame0);
	if (old_counter == 2)
		put_image(game, game->up_a.frame1);
	if (old_counter == 4)
		put_image(game, game->up_a.frame2);
	if (old_counter == 6)
		put_image(game, game->up_a.frame3);
	if (old_counter == 8)
		put_image(game, game->up_a.frame4);
	if (old_counter == 10)
		put_image(game, game->up_a.frame5);
	if (old_counter == 12)
		put_image(game, game->up_a.frame6);
	if (old_counter == 14)
		put_image(game, game->up_a.frame7);
	if (old_counter == 16)
		put_image(game, game->up_a.frame8);
	if (old_counter == 18)
		put_image(game, game->up_a.frame9);
	return (new_counter);
}

void	move_up(t_game *game)
{
	static int	i;

	check_up(game);
	game->character.mem = 4;
	if (i == 0)
		i = print_frame_up(game, 0, 2);
	else if (i == 2)
		i = print_frame_up(game, 2, 4);
	else if (i == 4)
		i = print_frame_up(game, 4, 6);
	else if (i == 6)
		i = print_frame_up(game, 6, 8);
	else if (i == 8)
		i = print_frame_up(game, 8, 10);
	else if (i == 10)
		i = print_frame_up(game, 10, 12);
	else if (i == 12)
		i = print_frame_up(game, 12, 14);
	else if (i == 14)
		i = print_frame_up(game, 14, 16);
	else if (i == 16)
		i = print_frame_up(game, 16, 18);
	else if (i == 18)
		i = print_frame_up(game, 18, 0);
	return ;
}
