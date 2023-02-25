/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:29:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 03:25:07 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_maker(t_game *game, int y, int x)
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

static void	map_check_one(t_game *game, int y, int x)
{
	if (!is_surrounded_by_trees(game, y, x))
		endgame("Not surrounded by trees!", game, map_char_error);
	else if (!is_rectangular(game))
		endgame("Map is not rectangular!", game, map_char_error);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid character in map", game, map_char_error);
	check_map_maker(game, y, x);
	return ;
}

void	render_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			map_check_one(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	return ;
}
