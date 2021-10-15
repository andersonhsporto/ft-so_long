/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/15 15:39:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_so_long(t_game *game)
{
	game->mlx_pointer = mlx_init();
	game->window_pointer = mlx_new_window(game->mlx_pointer, (game->plot.length * 32),
		(game->plot.height * 32), "./so_long");
	if (!game->i.movements)
		game->i.movements = 0;
}



// int	check_wall(t_game *parameter)
// {
// 	if (parameter->character.x < 0 || parameter->character.x > 500)
// 		return(0);
// 	return(1);
// }