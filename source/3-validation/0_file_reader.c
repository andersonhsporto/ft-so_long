/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_file_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:24:52 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 19:17:27 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	basic_validation(t_game *game);
static bool	all_line_is_same_size(char **map);
static void	char_validation(t_game *game, int y, int x);

void	validate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	basic_validation(game);
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

static void	basic_validation(t_game *game)
{
	if (is_elements_number_valid(&game->i))
	{
		free_map(game);
		endgame("Invalid file: wrong number of elements", game, error);
	}
	if (all_line_is_same_size(game->plot.map) == false) {
		free_map(game);
		endgame("Invalid file: lines are not the same size!", game, error);
	}
	if (is_rectangular(game) == false) {
		endgame("Map is not rectangular!", game, map_char_error);
	}
	return ;
}

static void	char_validation(t_game *game, int y, int x)
{
	if (!is_surrounded_by_trees(game, y, x))
		endgame("Not surrounded by trees!", game, map_char_error);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid character in map", game, map_char_error);
	return ;
}

static bool	all_line_is_same_size(char **map)
{
	const size_t	line = ft_strlen(map[0]);
	int				i;

	i = 0;
	while (map[i] != 0)
	{
		if (line != ft_strlen(map[i]))
			return (false);
		i++;
	}
	return (true);
}
