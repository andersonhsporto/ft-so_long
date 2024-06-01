/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_file_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:24:52 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 17:28:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	line_validation(char **map);
static void	char_validation(t_game *game, int y, int x);

void	validate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	if (!is_rectangular(game))
		endgame("Map is not rectangular!", game, map_char_error);
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			char_validation(game, y, x);
			x++;
		}
		y++;
	}
	return ;
}

int	len_map_validation(char **map)
{
	if (line_validation(map)) {
		return (ft_strlen(map[0]));
	}
	return (0);
}

static void	char_validation(t_game *game, int y, int x)
{
	if (!is_surrounded_by_trees(game, y, x))
		endgame("Not surrounded by trees!", game, map_char_error);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid character in map", game, map_char_error);
	return ;
}

static bool	line_validation(char **map)
{
	int		i;
	t_point	point;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			return (false);
		}
		i++;
	}
	return (true);
}
