/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_endgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:23:05 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/02 22:30:34 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	gameover(t_game *game, char *message);

void	destroy_image(t_game *game)
{
	if (game->state == image_init) {
		mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
		mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
		mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
		mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
		mlx_destroy_image(game->mlx_pointer, game->character.ptr);
		mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
		mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
		mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
		mlx_destroy_window(game->mlx_pointer, game->window_pointer);
		mlx_destroy_display(game->mlx_pointer);
	}
	return ;
}

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
	else if (i == map_char_error) {
		free_map(game);
		printf(RED"Error\n%s\n"ENDC, message);
		exit(EXIT_FAILURE);
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
	exit(EXIT_FAILURE);
}

static void	gameover(t_game *game, char *message)
{
	printf("%s\n", message);
	destroy_image(game);
	free_map(game);
	free(game->mlx_pointer);
	exit(EXIT_SUCCESS);
}
