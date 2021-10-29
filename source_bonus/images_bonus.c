/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:09:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/28 20:26:08 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_sprites(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_collec(game, i, j);
	init_link_down(game, i, j);
	init_link_left(game, i, j);
	init_link_right(game, i, j);
	init_link_up(game, i, j);
	init_enemies(game, i, j);
	game->portal_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/portal/p1.xpm", &i, &j);
	game->portal_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/portal/p2.xpm", &i, &j);
	game->portal_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/portal/p3.xpm", &i, &j);
	game->portal_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/portal/p4.xpm", &i, &j);
	return ;
}

void	init_images(t_game	*game)
{
	init_sprites(game);
	game->wall = new_sprite(game->mlx_pointer,
			"./img/tree.xpm");
	game->floor = new_sprite(game->mlx_pointer,
			"./img/floor.xpm");
	game->collect = new_sprite(game->mlx_pointer,
			"./img/potion.xpm");
	game->portal = new_sprite(game->mlx_pointer,
			"./img/portal/p1.xpm");
	game->character = new_sprite(game->mlx_pointer,
			"./img/static/down.xpm");
	game->character_l = new_sprite(game->mlx_pointer,
			"./img/static/left.xpm");
	game->character_r = new_sprite(game->mlx_pointer,
			"./img/static/right.xpm");
	game->character_u = new_sprite(game->mlx_pointer,
			"./img/static/up.xpm");
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.x = 0;
	img.y = 0;
	img.mem = 0;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

void	free_map(t_game	*game)
{
	int	i;

	i = 0;
	while (game->plot.map[i] != 0)
	{
		free(game->plot.map[i]);
		game->plot.map[i] = NULL;
		i++;
	}
	free(game->plot.map);
	return ;
}
