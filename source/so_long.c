/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:30:00 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_game *game, char *path);
static bool	check_arg(const char *argv);
static void	init_hook(t_game *game, int event, \
int mask, int (*f)());

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2 && (check_arg(argv[1])))
		init_game(&game, argv[1]);
	else if ((argc == 2 && !(check_arg(argv[1]))))
		endgame("Can't open file. The format is not supported!", &game, error);
	else if (argc > 2)
		endgame("Can't open multiple files!", &game, error);
	else
		endgame("Please specify file name!", &game, error);
	return (0);
}

static void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_images(game);
	render_map(game);
	init_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, key_check);
	init_hook(game, DESTROY_NOTIFY, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_maker);
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

static void	init_hook(t_game *game, int event, \
int mask, int (*f)())
{
	mlx_hook(
		game->window_pointer,
		event,
		mask,
		f,
		game);
}
