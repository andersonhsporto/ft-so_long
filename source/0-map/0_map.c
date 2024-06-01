/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:29:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 16:31:54 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_sprite(t_game *game, int y, int x);

void	render_map(t_game *game)
{
	t_point	coord;

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
	return ;
}

static void	render_sprite(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->portal.x = x * SPRITE_SIZE;
		game->portal.y = y * SPRITE_SIZE;
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->portal.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->wall.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->plot.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->collect.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}
