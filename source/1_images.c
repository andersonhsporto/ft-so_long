/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_images.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:09:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:41:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/path.h"

void	init_window(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if (is_larger_than_window(game))
	{
		free_map(game);
		mlx_destroy_display(game->mlx_pointer);
		free(game->mlx_pointer);
		endgame("Map size larger than display resolution", game, error);
	}
	else
	{
		game->window_pointer = mlx_new_window(\
		game->mlx_pointer, \
		(game->plot.length * SPRITE_SIZE), \
		(game->plot.height * SPRITE_SIZE), \
		WINDOW_NAME);
	}
}

void	init_images(t_game	*game)
{
	game->wall = new_sprite(game->mlx_pointer, WALL_PATH);
	game->floor = new_sprite(game->mlx_pointer, FLOOR_PATH);
	game->collect = new_sprite(game->mlx_pointer, COLLECT_PATH);
	game->portal = new_sprite(game->mlx_pointer, PORTAL_PATH);
	game->character = new_sprite(game->mlx_pointer, CHAR_PATH);
	game->character_l = new_sprite(game->mlx_pointer, CHAR_L_PATH);
	game->character_r = new_sprite(game->mlx_pointer, CHAR_R_PATH);
	game->character_u = new_sprite(game->mlx_pointer, CHAR_U_PATH);
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}
