/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/01 18:33:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	len_map(char **map, t_game *game)
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
