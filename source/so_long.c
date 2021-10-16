/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/16 20:11:54 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		mlx_hook(game.window_pointer, 17, (0L), red_cross, &game);
		mlx_hook(game.window_pointer, 12, (1L << 15), mini_maker, &game);
		mlx_loop(game.mlx_pointer);
	}
	if ((argc == 2 && !(check_arg(argv[1]))))
		endgame("Can't open file. The format is not supported!", &game, 1);
	if (argc > 2)
		endgame("Can't open multiple files!", &game, 1);
	else
		endgame("Please specify file name!", &game, 1);
	return (0);
}
