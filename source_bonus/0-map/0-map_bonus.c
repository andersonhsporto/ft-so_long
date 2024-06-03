/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-map_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:35:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/02 21:50:04 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void render_sprite(t_game *game, int y, int x);

void render_map(t_game *game)
{
	t_point coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			render_sprite(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	return;
}

static void render_sprite(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->portal.x = x * SPRITE_SIZE;
		game->portal.y = y * SPRITE_SIZE;
		print_portal(game);
	}
	else if (game->plot.map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
								game->wall.ptr, (32 * x), (32 * y));
		if (game->plot.map[game->plot.height - 1][x] == '1')
		{
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
									game->floor.ptr, (32 * x), (32 * game->plot.height));
			print_map_string(game);
		}
	}
	else if (game->plot.map[y][x] == 'C')
		print_potion(game, y, x);
	else if (ft_strchr("Ff", game->plot.map[y][x]))
		print_e(game, y, x);
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
								game->floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}
