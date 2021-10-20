/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:29:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/19 22:01:30 by anhigo-s         ###   ########.fr       */
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
	if ((game->plot.map[game->plot.height - 1][x] != '1') ||
			(game->plot.map[0][x] != '1') || (game->plot.map[y]
			[game->plot.length - 1] != '1') || (game->plot.map[y]
			[0] != '1'))
	{
		endgame("Not surrounded by trees!", game, 1);
	}
	if (game->plot.height == game->plot.length)
	{
		endgame("Map is not rectangular!", game, 1);
	}
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
	{
		endgame("Map is not rectangular!", game, 1);
	}
	check_map_maker(game, y, x);
	return ;
}

void	map_maker(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			map_check_one(game, y, x);
			x++;
		}
		y++;
	}
	return ;
}

static t_counter	start_counter(char *string_map, t_game *game, int i)
{
	t_counter	cnt;

	cnt.collectible = 0;
	cnt.start = 0;
	cnt.exit = 0;
	cnt.movements = 0;
	cnt.empty = 0;
	while (string_map[i] != '\0')
	{
		if ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])))
			endgame("Invalid, file!", game, 1);
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
	if (!(cnt.collectible > 0 && cnt.exit > 0 && cnt
			.start == 1))
		endgame("Invalid, file!", game, 1);
	return (cnt);
}

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		endgame("Can't find file!", game, 1);
	game->plot.temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (!game->plot.line)
			break ;
		game->plot.temp = gnl_strjoin(game->plot.temp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = start_counter(game->plot.temp, game, 0);
	game->plot.map = ft_split(game->plot.temp, '\n');
	free(game->plot.temp);
	game->plot.length = len_map(game->plot.map, game);
	close(fd);
	return ;
}
