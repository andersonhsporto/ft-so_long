/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:20:18 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/25 01:14:07 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	print_fire(t_game *game, void *frame, int x, int y)
{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
	frame, (32 * x), (32 * y));
}

void	print_e(t_game *game, int y, int x)
{
	if (game->i.movements == 0)
		print_fire(game, game->public.enemy_a.frame1, x, y);
	else if (game->plot.map[y][x] == 'F' && game->plot.map[y + 1][x] == '0')
	{
		print_fire(game, game->public.enemy_a.frame1, x, y);
		game->plot.map[y][x] = '0';
		game->plot.map[y + 1][x] = 'F';
	}
	else if (game->plot.map[y][x] == 'F' && game->plot.map[y + 1][x] == '1')
	{
		print_fire(game, game->public.enemy_a.frame1, x, y);
		game->plot.map[y][x] = 'f';
	}
	else if (game->plot.map[y][x] == 'f' && game->plot.map[y - 1][x] == '0')
	{
		print_fire(game, game->public.enemy_a.frame1, x, y);
		game->plot.map[y][x] = '0';
		game->plot.map[y - 1][x] = 'f';
	}
	else if (game->plot.map[y][x] == 'f' && game->plot.map[y - 1][x] == '1')
	{
		print_fire(game, game->public.enemy_a.frame1, x, y);
		game->plot.map[y][x] = 'F';
	}
}


// void	print_e(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (game->plot.map[y])
// 	{
// 		x = 0;
// 		while (game->plot.map[y][x])
// 		{
// 			if (ft_strchr("Ff", game->plot.map[y][x]))
// 			{
// 				print_fire_check(game, y, x);
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return ;
// }
