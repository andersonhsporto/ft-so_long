/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/28 22:16:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && (check_arg(argv[1])))
	{
		init_map(&game, argv[1]);
		init_so_long(&game);
		init_images(&game);
		map_maker(&game);
		mlx_hook(game.window_pointer, 3, (1L << 1), key_check, &game);
		mlx_hook(game.window_pointer, 17, (0L), red_cross, &game);
		mlx_hook(game.window_pointer, 12, (1L << 15), mini_maker, &game);
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
