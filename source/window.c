/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/07 18:30:26 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_so_long(t_game *teste)
{
	teste->mlx_pointer = mlx_init();
	teste->window_pointer = mlx_new_window(teste->mlx_pointer, 500, 50, "so_long");
}
