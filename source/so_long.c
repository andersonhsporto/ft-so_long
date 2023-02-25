/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:07:36 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_game *game, char *path);
static bool	check_arg(const char *argv);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2 && (check_arg(argv[1])))
	{
		init_game(&game, argv[1]);
	}
	if ((argc == 2 && !(check_arg(argv[1]))))
		endgame("Can't open file. The format is not supported!", &game, error);
	if (argc > 2)
		endgame("Can't open multiple files!", &game, error);
	else
		endgame("Please specify file name!", &game, error);
	return (0);
}

static void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_so_long(game);
	init_images(game);
	map_maker(game);
	mlx_hook(game->window_pointer, \
		KEY_RELEASE, KEY_RELEASE_MASK, key_check, game);
	mlx_hook(game->window_pointer, \
		DESTROY_NOTIFY, NO_EVENT_MASK, red_cross, game);
	mlx_hook(game->window_pointer, \
		12, EXPOSURE_MASK, mini_maker, game);
	mlx_loop(game->mlx_pointer);
}

static bool	check_arg(const char *argv)
{
	size_t	len;
	char	*string;

	len = 0;
	string = ft_strrchr(argv, '.');
	if (string)
	{
		len = ft_strlen(string);
		if (ft_memcmp(string, ".ber", len) == 0)
			return (true);
	}
	return (false);
}
