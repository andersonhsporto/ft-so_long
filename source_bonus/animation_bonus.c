/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 02:37:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/30 00:52:05 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	fix_pos(int keycode, t_game *game)
{
	if (keycode == LEFT)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_l.ptr, game->character.x, game->character.y);
	if (keycode == RIGHT)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_r.ptr, game->character.x, game->character.y);
	if (keycode == UP)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_u.ptr, game->character.x, game->character.y);
	if (keycode == DOWN)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character.ptr, game->character.x, game->character.y);
	return (0);
}

void	put_image(t_game *game, void *frame)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		frame, game->character.x, game->character.y);
	return ;
}

void	print_portal(t_game *game)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame1, game->portal.x, game->portal.x);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame2, game->portal.x, game->portal.x);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal_a.frame3, game->portal.x, game->portal.x);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return ;
}

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < pause)
	{
		now = clock();
	}
	return ;
}
