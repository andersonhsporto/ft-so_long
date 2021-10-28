/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/28 01:02:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	red_cross(t_game *game)
{
	endgame("", game, -1);
	return (0);
}

int	mini_maker(t_game *game)
{
	map_maker(game);
	if (game->i.movements == 0)
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (game->portal.x), (game->portal.y));
		player_init(game);
	}
	if (game->character.mem == down)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character.ptr, game->character.x, game->character.y);
	if (game->character.mem == left)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_l.ptr, game->character.x, game->character.y);
	if (game->character.mem == right)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_r.ptr, game->character.x, game->character.y);
	if (game->character.mem == up)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_u.ptr, game->character.x, game->character.y);
	return (0);
}

void	endgame(char *message, t_game *game, int i)
{
	if (i == -1)
	{
		printf("%s\n", message);
		destroy_image(game);
		exit(0);
		return ;
	}
	if (i == 2)
	{
		printf(RED"Error\n%s\n"ENDC, message);
		exit(1);
	}
	printf(RED"Error\n%s\n"ENDC, message);
	destroy_image(game);
	exit(1);
	return ;
}

int	check_arg(const char *argv)
{
	size_t	len;
	char	*string;

	len = 0;
	string = ft_strrchr(argv, '.');
	if (string)
	{
		len = ft_strlen(string);
		if (ft_memcmp(string, ".ber", len) == 0)
			return (1);
	}
	return (0);
}

void	init_so_long(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlx_pointer = mlx_init();
	mlx_get_screen_size(game->mlx_pointer, &i, &j);
	if (((game->plot.length * 32) > i) || ((game->plot.height * 32) > j))
	{
		free_map(game);
		mlx_destroy_display(game->mlx_pointer);
		free(game->mlx_pointer);
		endgame("Map size larger than display resolution", game, 2);
	}
	else
	{
		game->window_pointer = mlx_new_window(game->mlx_pointer,
				(game->plot.length * 32), ((game->plot.height * 32) + 16),
				"./so_long");
		mlx_set_font(game->mlx_pointer, game->window_pointer,
			"-bitstream-*-*-*-*-*-*-*-*");
	}
}
