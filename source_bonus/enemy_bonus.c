/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:20:18 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/22 21:06:31 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_enemies(t_game *game, int i, int j)
{
	game->public.enemy_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire1.xpm", &i, &j);
	game->public.enemy_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire2.xpm", &i, &j);
	game->public.enemy_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire3.xpm", &i, &j);
	game->public.enemy_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/fire-32x32/fire4.xpm", &i, &j);
	return ;
}

void	print_e(t_game *game, int y, int x)
{
	static int i;

	if (i == 20)
	{
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->public.enemy_a.frame1, (32 * x), (32 * (y + 1)));
		game->plot.map[y+1][x] = 'F';
		game->plot.map[y][x] = '0';
		printf("ok\n");
	}
	else if (game->plot.map[y][x] == 'F' && game->plot.map[y + 1][x] == '1')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->public.enemy_a.frame1, (32 * x), (32 * (y - 1)));
		game->plot.map[y-1][x] = 'f';
		game->plot.map[y][x] = '0';
		printf("ok\n");
	}
	else if (game->plot.map[y][x] == 'f' && game->plot.map[y - 1][x] == '0')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->public.enemy_a.frame1, (32 * x), (32 * (y - 1)));
		game->plot.map[y-1][x] = 'f';
		game->plot.map[y][x] = '0';
		printf("ok\n");
	}
	if (i > 20)
	{
		i = 0;
	}
	i++;
	printf("%d\n", i);
	//i++;
}
/* void	move_enemies(t_game *game)
{
	if ()
	return ;
} */