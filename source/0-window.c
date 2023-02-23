/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/23 18:42:56 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	red_cross(t_game *game)
{
	endgame("", game, -1);
	return (0);
}

int	mini_maker(t_game *game)
{
	map_maker(game);
	if (game->i.movements == 0)
	{
		player_init(game);
	}
	if (game->character.mem == down)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character.ptr, game->character.x, game->character.y);
	if (game->character.mem == left)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_l.ptr, game->character.x, game->character.y);
	if (game->character.mem == right)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_r.ptr, game->character.x, game->character.y);
	if (game->character.mem == up)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_u.ptr, game->character.x, game->character.y);
	return (0);
}

void	endgame(char *message, t_game *game, int i)
{
	if (i == -1)
	{
		printf("%s\n", message);
		destroy_image(game);
		exit(0);
		return ;
	}
	if (i == 2)
	{
		printf(RED"Error\n%s\n"ENDC, message);
		exit(1);
	}
	if (i == 3)
	{
		printf(RED"Error\n%s\n"ENDC, message);
		free(game->plot.temp);
		exit(1);
	}
	printf(RED"Error\n%s\n"ENDC, message);
	destroy_image(game);
	exit(1);
	return ;
}
