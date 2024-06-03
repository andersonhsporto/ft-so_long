/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map_validation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:12:23 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 19:42:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_surrounded_by_trees(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1') || \
		(game->plot.map[0][x] != '1') || (game->plot.map[y] \
		[game->plot.length - 1] != '1') || (game->plot.map[y][0] != '1'))
	{
		return (false);
	}
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->plot.height == game->plot.length)
	{
		return (false);
	}
	return (true);
}

bool	is_valid_character(t_game *game, int y, int x)
{
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
	{
		return (false);
	}
	return (true);
}

bool	is_double_line(const char *string_map)
{
	size_t	i;

	i = 0;
	while (string_map[i])
	{
		if (string_map[i] == '\n' && string_map[i + 1] == '\n')
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_elements_number_valid(t_counter *cnt)
{
	if (\
	!(cnt->collectible > 0 && cnt->exit == 1 && \
	cnt->start == 1 && cnt->empty > 0))
	{
		return (true);
	}
	return (false);
}
