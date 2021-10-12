/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:29:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/12 00:25:39 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->wall.ptr, (26 * x), (32 * y));
	else if (game->plot.map[y][x] == 'C')
	{
		if ((game->character.x / 26) == x && (game->character.y / 32) == y)
		{
			game->plot.map[y][x] = '0';
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
				game->collect.ptr, (26 * x), (32 * y));
		}
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect.ptr, (26 * x), (32 * y));
	}
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->floor.ptr, (26 * x), (32 * y));
}

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
				game->character.x = (26 * x);
				game->character.y = (32 * y);
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
					game->character.ptr, (26 * x), (32 * y));
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	map_maker(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			check_map_maker(game, y, x);
			x++;
		}
		y++;
	}
	return ;
}

int	len_map(char **map)
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
			return (0);
		i++;
	}
	return (k);
}

void	init_map(t_game *game, char *path)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ; //verificar depois
	game->plot.temp = ft_strdup("");
	i = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (!game->plot.line)
			break ;
		game->plot.temp = gnl_strjoin(game->plot.temp, game->plot.line);
		free(game->plot.line);
		i++;
	}
	game->plot.map = ft_split(game->plot.temp, '\n');
	game->plot.height = i;
	game->plot.length = len_map(game->plot.map);
	close(fd);
	return ;
}
