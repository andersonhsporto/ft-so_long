/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_images_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 00:30:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/26 00:30:58 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	init_collec(t_game *game, int i, int j)
{
	game->collect_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/potion2.xpm", &i, &j);
	game->collect_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/potion3.xpm", &i, &j);
	game->collect_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/potion.xpm", &i, &j);
}
