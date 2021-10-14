/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:29:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/14 02:10:03 by anhigo-s         ###   ########.fr       */
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

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->wall.ptr, (32 * x), (32 * y));
	else if (game->plot.map[y][x] == 'C')
	{
		if ((game->character.x / 32) == x && (game->character.y / 32) == y)
		{
			game->plot.map[y][x] = '0';
			game->i.collectible--;
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
				game->collect.ptr, (32 * x), (32 * y));
		}
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect.ptr, (32 * x), (32 * y));
	}
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->floor.ptr, (32 * x), (32 * y));
}

void	map_check_two(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'C')
		game->i.collectible++;
	else if (game->plot.map[y][x] == 'E')
		game->i.map_exit++;
	else if (game->plot.map[y][x] == 'P')
		game->i.starting++;
	if (game->i.collectible > 0 || game->i.map_exit > 0 || game->i.starting == 1)
		check_map_maker(game, y, x);
	else
	{
		printf("Error\nInvalid Map\n");
		exit(1);
	}
	return ;
}

void	map_check_one(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1') ||
			(game->plot.map[0][x] != '1') || (game->plot.map[y]
			[game->plot.length - 1] != '1') || (game->plot.map[y]
			[0] != '1'))
	{
		printf("Error\nNot surrounded by trees!\n");
		exit(1);
	}
	if (game->plot.height == game->plot.length)
	{
		printf("Error\nMap is not rectangular!\n");
		exit(1);
	}
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
	{
		printf("Error\nInvalid Map");
		exit(1);
	}
	map_check_two(game, y, x);
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

void	exit_game(int fd)
{
	printf("Error\nCan't find file!\n");
	close(fd);
	exit(1);
}

void	init_map(t_game *game, char *path)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_game(fd);
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
