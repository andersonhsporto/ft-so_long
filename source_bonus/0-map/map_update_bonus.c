/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/02 21:27:37 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <time.h>

void	print_map_string(t_game *game)
{
	char	*string;

	string = ft_itoa(game->i.movements);
	if (game->plot.length < 9)
	{
		mlx_string_put(game->mlx_pointer, game->window_pointer, 4,
			((game->plot.height) * 32) + 14, 0xFFFFFF, "Movements: ");
		mlx_string_put(game->mlx_pointer, game->window_pointer, 68,
			((game->plot.height) * 32) + 14, 0xFFFFFF, string);
	}
	else
	{
		mlx_string_put(game->mlx_pointer, game->window_pointer,
			(((game->plot.length - 4) / 2) * 32),
			(game->plot.height * 32) + 12, 0xFFFFFF, "Movements: ");
		mlx_string_put(game->mlx_pointer, game->window_pointer,
			(((game->plot.length - 4) / 2) * 32) + 100,
			(game->plot.height * 32) + 12, 0xFFFFFF, string);
	}
	free(string);
	string = NULL;
	return ;
}

void	print_potion(t_game *game, int y, int x)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect_a.frame1, x * 32, y * 32);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect_a.frame0, x * 32, y * 32);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect_a.frame2, x * 32, y * 32);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return ;
}

int	fix_image(t_game *game)
{
	delay(40);
	mini_maker(game);
	game->i.time++;
	return (0);
}
