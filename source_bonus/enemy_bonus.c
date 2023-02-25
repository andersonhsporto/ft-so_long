/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:20:18 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 01:53:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_fire(t_game *game, int y, int x)
{
	static int	i;

	if (i > 0 && i < SPEED)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->public.enemy_a.frame1, x * 32, y * 32);
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->public.enemy_a.frame2, x * 32, y * 32);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->public.enemy_a.frame3, x * 32, y * 32);
	}
	if (i >= (SPEED * 8) && i < (SPEED * 12))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->public.enemy_a.frame4, x * 32, y * 32);
	}
	if (i == (SPEED * 12))
		i = 0;
	i++;
	return ;
}

static void	check_fire(t_game *game, int x, int y, char z)
{
	if (((ft_strchr("fF", game->plot.map[game->character.y / 32]
					[(game->character.x + 31) / 32]))) || (ft_strchr
			("fF", game->plot.map [game->character.y / 32]
				[(game->character.x) / 32])))
	{
		endgame(RED"\n\nThe End! you died :( "ENDC, game, -1);
	}
	else if (z == 'Q')
	{
		print_fire(game, y, x);
	}
	else
	{
		game->plot.map[y][x] = z;
		print_fire(game, y, x);
	}
	return ;
}

void	print_e(t_game *game, int y, int x)
{
	static int	i;

	if (i % 15)
		check_fire(game, x, y, 'Q');
	else if (game->plot.map[y][x] == 'F' && game->plot.map[y + 1][x] == '0')
	{
		check_fire(game, x, y, '0');
		game->plot.map[y + 1][x] = 'F';
	}
	else if (game->plot.map[y][x] == 'F' && (ft_strchr("1C",
		game->plot.map[y + 1][x])))
		check_fire(game, x, y, 'f');
	else if (game->plot.map[y][x] == 'f' && game->plot.map[y - 1][x] == '0')
	{
		check_fire(game, x, y, '0');
		game->plot.map[y - 1][x] = 'f';
	}
	else if (game->plot.map[y][x] == 'f' && (ft_strchr("1C",
		game->plot.map[y - 1][x])))
	{
		check_fire(game, x, y, 'F');
	}
	i++;
}

void	init_enemies(t_game *game, int i, int j)
{
	game->public.enemy_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire1.xpm", &i, &j);
	game->public.enemy_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire2.xpm", &i, &j);
	game->public.enemy_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire3.xpm", &i, &j);
	game->public.enemy_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire4.xpm", &i, &j);
	return ;
}

void	destroy_enemies(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->public.enemy_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->public.enemy_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->public.enemy_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->public.enemy_a.frame4);
	return ;
}
