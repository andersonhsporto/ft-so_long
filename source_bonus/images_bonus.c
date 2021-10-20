/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:09:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/20 01:51:37 by anhigo-s         ###   ########.fr       */
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
		endgame("Map size larger than display resolution", game, 1);
	game->window_pointer = mlx_new_window(game->mlx_pointer,
			(game->plot.length * 32), (game->plot.height * 32), "./so_long");
	if (!game->i.movements)
		game->i.movements = 0;
}

void	init_link_down(t_game *game, int i, int j)
{
	game->down_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D1.xpm", &i, &j);
	game->down_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D2.xpm", &i, &j);
	game->down_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D3.xpm", &i, &j);
	game->down_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D4.xpm", &i, &j);
	game->down_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D5.xpm", &i, &j);
	game->down_a.frame5 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D6.xpm", &i, &j);
	game->down_a.frame6 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D7.xpm", &i, &j);
	game->down_a.frame7 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D8.xpm", &i, &j);
	game->down_a.frame8 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D9.xpm", &i, &j);
	game->down_a.frame9 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/D10.xpm", &i, &j);
	return ;
}

void	init_link_right(t_game *game, int i, int j)
{
	game->right_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r1.xpm", &i, &j);
	game->right_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r2.xpm", &i, &j);
	game->right_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r3.xpm", &i, &j);
	game->right_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r4.xpm", &i, &j);
	game->right_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r5.xpm", &i, &j);
	game->right_a.frame5 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r6.xpm", &i, &j);
	game->right_a.frame6 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r7.xpm", &i, &j);
	game->right_a.frame7 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r8.xpm", &i, &j);
	game->right_a.frame8 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r9.xpm", &i, &j);
	game->right_a.frame9 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/r10.xpm", &i, &j);
	return ;
}

void	init_link_left(t_game *game, int i, int j)
{
	game->left_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l1.xpm", &i, &j);
	game->left_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l2.xpm", &i, &j);
	game->left_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l3.xpm", &i, &j);
	game->left_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l4.xpm", &i, &j);
	game->left_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l5.xpm", &i, &j);
	game->left_a.frame5 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l6.xpm", &i, &j);
	game->left_a.frame6 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l7.xpm", &i, &j);
	game->left_a.frame7 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l8.xpm", &i, &j);
	game->left_a.frame8 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l9.xpm", &i, &j);
	game->left_a.frame9 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/l10.xpm", &i, &j);
	return ;
}

void	init_link_up(t_game *game, int i, int j)
{
	game->up_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u1.xpm", &i, &j);
	game->up_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u2.xpm", &i, &j);
	game->up_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u3.xpm", &i, &j);
	game->up_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u4.xpm", &i, &j);
	game->up_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u5.xpm", &i, &j);
	game->up_a.frame5 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u6.xpm", &i, &j);
	game->up_a.frame6 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u7.xpm", &i, &j);
	game->up_a.frame7 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u8.xpm", &i, &j);
	game->up_a.frame8 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u9.xpm", &i, &j);
	game->up_a.frame9 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/link/u10.xpm", &i, &j);
	return ;
}

void	init_sprites(t_game	*game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	init_link_down(game, i, j);
	init_link_left(game, i, j);
	init_link_right(game, i, j);
	init_link_up(game, i, j);
	game->portal_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p1.xpm", &i, &j);
	game->portal_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p2.xpm", &i, &j);
	game->portal_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p3.xpm", &i, &j);
	game->portal_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer, "./img/portal/p4.xpm", &i, &j);
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
