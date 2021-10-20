/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/20 02:08:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	red_cross(t_game *game)
{
	endgame("", game, -1);
	return (0);
}

int	mini_maker(t_game *game)
{
	map_maker(game);
	if (game->i.movements == 0)
		player_init(game);
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
	printf("Error\n%s\n", message);
	destroy_image(game);
	exit(1);
	return ;
}

int	check_arg(const char	*argv)
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
