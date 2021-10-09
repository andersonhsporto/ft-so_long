/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/08 22:14:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_so_long(t_game *teste)
{
	teste->mlx_pointer = mlx_init();
	teste->window_pointer = mlx_new_window(teste->mlx_pointer, 500, 100, "so_long");
}

int	check_wall(t_game *parameter)
{
	if (parameter->character.x < 0 || parameter->character.x > 500)
		return(0);
	return(1);
}