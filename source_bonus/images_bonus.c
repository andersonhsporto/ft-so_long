/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:09:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/18 03:25:33 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_so_long(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlx_pointer = mlx_init();
	mlx_get_screen_size(game->mlx_pointer, &i, &j);
	if (((game->plot.length  * 32) > i) || ((game->plot.height * 32) > j))
		endgame("Error\n Map size larger than monitor", game, 1);
	game->window_pointer = mlx_new_window(game->mlx_pointer,
			(game->plot.length * 32), (game->plot.height * 32), "./so_long");
	if (!game->i.movements)
		game->i.movements = 0;
}

void	init_sprites(t_game	*game)
{
	int i;
	int j;
	game->portal_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p1.xpm", &i, &j);
	game->portal_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p2.xpm", &i, &j);
	game->portal_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p3.xpm", &i, &j);
	game->portal_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p4.xpm", &i, &j);
	game->down_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p1.xpm", &i, &j);
	game->down_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p2.xpm", &i, &j);
	game->down_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p3.xpm", &i, &j);
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
