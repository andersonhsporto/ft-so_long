/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_endgame_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 00:20:52 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 20:03:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	gameover(t_game *game, char *message);

void	free_map(t_game	*game)
{
	while (game->plot.height > 0)
	{
		free(game->plot.map[game->plot.height - 1]);
		game->plot.height--;
	}
	free(game->plot.map);
	return ;
}

void	endgame(char *message, t_game *game, enum e_state i)
{
	if (i == event_ending || i == game_over)
		gameover(game, message);
	else if (i == error || i == file_error)
	{
		print_exit_err_message(message);
	}
	else if (i == map_char_error)
	{
		free_map(game);
		printf(RED"Error\n%s\n"ENDC, message);
		exit(1);
	}
	destroy_image(game);
	free_map(game);
	free(game->mlx_pointer);
	print_exit_err_message(message);
	return ;
}

void	print_exit_err_message(char *message)
{
	printf(RED"Error\n%s\n"ENDC, message);
	exit(1);
}

static void	gameover(t_game *game, char *message)
{
	printf("%s\n", message);
	destroy_image(game);
	free_map(game);
	free(game->mlx_pointer);
	exit(0);
}
