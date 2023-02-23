/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:29:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:28:24 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->portal.x = x * 32;
		game->portal.y = y * 32;
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (32 * x), (32 * y));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->wall.ptr, (32 * x), (32 * y));
	else if (game->plot.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect.ptr, (32 * x), (32 * y));
	}
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->floor.ptr, (32 * x), (32 * y));
}

static void	map_check_one(t_game *game, int y, int x)
{
	if (!is_surrounded_by_trees(game, y, x))
	{
		endgame("Not surrounded by trees!", game, 4);
	}
	if (!is_rectangular(game))
	{
		endgame("Map is not rectangular!", game, 4);
	}
	if (!is_valid_character(game, y, x))
	{
		endgame("Invalid character in map", game, 4);
	}
	check_map_maker(game, y, x);
	return ;
}

void	map_maker(t_game *game)
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

static t_counter	start_counter(char *string_map, t_game *game, int i)
{
	t_counter	cnt;

	cnt = new_counter();
	while (string_map[i] != '\0')
	{
		if ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])))
			endgame("Invalid, file!", game, 3);
		if (string_map[i] == 'C')
			cnt.collectible++;
		else if (string_map[i] == 'E')
			cnt.exit++;
		else if (string_map[i] == 'P')
			cnt.start++;
		else if (string_map[i] == '0')
			cnt.empty++;
		i++;
	}
	if (!(cnt.collectible > 0 && cnt.exit == 1 && cnt
			.start == 1 && cnt.empty > 0))
		endgame("Invalid, file!", game, 3);
	return (cnt);
}

void	init_map(t_game *game, char *path)
{
	int		fd;
	char	*temp;

	fd = open_file(path);
	temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		temp = gnl_strjoinfree(temp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = start_counter(temp, game, 0);
	game->plot.map = ft_split(temp, '\n');
	free(temp);
	game->plot.length = len_map(game->plot.map, game);
	close(fd);
	return ;
}
