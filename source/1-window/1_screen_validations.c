/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_screen_validations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:12:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 03:21:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_point	get_screen_size(t_game *game)
{
	t_point	point;

	mlx_get_screen_size(game->mlx_pointer, &point.x, &point.y);
	return (point);
}

bool	is_larger_than_window(t_game *game)
{
	t_point	screen_size;

	screen_size = get_screen_size(game);
	return (\
	((game->plot.length * SPRITE_SIZE) > screen_size.x) \
	|| \
	((game->plot.height * SPRITE_SIZE) > screen_size.y) \
	);
}
