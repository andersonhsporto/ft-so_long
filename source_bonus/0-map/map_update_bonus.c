/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/23 21:54:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_init(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			if (game->plot.map[y][x] == 'P')
			{
				game->character.x = (32 * x);
				game->character.y = (32 * y);
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
					game->character.ptr, (32 * x), (32 * y));
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	len_map_validation(char **map, t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		j = ft_strlen(map[i]);
		if (k != j)
		{
			free_map(game);
			endgame("Invalid, file!", game, 2);
		}
		i++;
	}
	return (k);
}

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
