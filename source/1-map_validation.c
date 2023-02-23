/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-map_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:12:23 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:12:31 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
