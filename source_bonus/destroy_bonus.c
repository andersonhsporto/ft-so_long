/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:07:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/28 20:26:01 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_collec_old(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->collect_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->collect_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->collect_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
	mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
	mlx_destroy_image(game->mlx_pointer, game->portal_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->portal_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->portal_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->portal_a.frame4);
	return ;
}

static void	destroy_player_dr(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame4);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame5);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame6);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame7);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame8);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame9);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame4);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame5);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame6);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame7);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame8);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame9);
	return ;
}

static void	destroy_player_lu(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame4);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame5);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame6);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame7);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame8);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame9);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame4);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame5);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame6);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame7);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame8);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame9);
	return ;
}

void	destroy_image(t_game *game)
{
	destroy_enemies(game);
	destroy_collec_old(game);
	destroy_player_dr(game);
	destroy_player_lu(game);
	mlx_destroy_window(game->mlx_pointer, game->window_pointer);
	mlx_destroy_display(game->mlx_pointer);
	free_map(game);
	free(game->mlx_pointer);
	return ;
}
