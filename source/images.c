/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:09:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:31:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_so_long(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if (is_larger_than_window(game))
	{
		free_map(game);
		mlx_destroy_display(game->mlx_pointer);
		free(game->mlx_pointer);
		endgame("Map size larger than display resolution", game, 2);
	}
	else
	{
		game->window_pointer = mlx_new_window(game->mlx_pointer,
				(game->plot.length * 32), (game->plot.height * 32),
				WINDOW_NAME);
	}
}

void	init_images(t_game	*game)
{
	game->wall = new_sprite(game->mlx_pointer,
			"./img/tree.xpm");
	game->floor = new_sprite(game->mlx_pointer,
			"./img/floor.xpm");
	game->collect = new_sprite(game->mlx_pointer,
			"./img/potion.xpm");
	game->portal = new_sprite(game->mlx_pointer,
			"./img/portal.xpm");
	game->character = new_sprite(game->mlx_pointer,
			"./img/link_sprites/down_1__.xpm");
	game->character_l = new_sprite(game->mlx_pointer,
			"./img/link_sprites/left_1__.xpm");
	game->character_r = new_sprite(game->mlx_pointer,
			"./img/link_sprites/right_1__.xpm");
	game->character_u = new_sprite(game->mlx_pointer,
			"./img/link_sprites/up_1__.xpm");
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

void	destroy_image(t_game *game)
{
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
	free_map(game);
	free(game->mlx_pointer);
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
