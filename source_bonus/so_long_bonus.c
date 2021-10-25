/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/25 01:12:10 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < pause)
	{
		now = clock();
	}
	return ;
}

int	fix_image(t_game *game)
{
	static int	i;

	if (i == SPEED)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame1, game->portal.x, game->portal.x);
	if (i == (2 * SPEED))
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame2, game->portal.x, game->portal.x);
	if (i == (4 * SPEED))
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame3, game->portal.x, game->portal.x);
	if (i == (5 * SPEED))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame4, game->portal.x, game->portal.x);
		i = 0;
	}
	delay(50);
	mini_maker(game);
	i++;
	game->i.time++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && (check_arg(argv[1])))
	{
		game.character.mem = 0;
		init_map(&game, argv[1]);
		init_so_long(&game);
		init_images(&game);
		map_maker(&game);
		mlx_hook(game.window_pointer, 2, (1L << 0), key_check, &game);
		mlx_hook(game.window_pointer, 3, (1L << 1), fix_pos, &game);
		mlx_hook(game.window_pointer, 17, (0L), red_cross, &game);
		mlx_hook(game.window_pointer, 12, (1L << 15), mini_maker, &game);
		mlx_loop_hook(game.mlx_pointer, fix_image, &game);
		mlx_loop(game.mlx_pointer);
	}
	if ((argc == 2 && !(check_arg(argv[1]))))
		endgame("Can't open file. The format is not supported!", &game, 2);
	if (argc > 2)
		endgame("Can't open multiple files!", &game, 2);
	else
		endgame("Please specify file name!", &game, 2);
	return (0);
}
