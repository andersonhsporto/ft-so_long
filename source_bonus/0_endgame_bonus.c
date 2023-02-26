/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_endgame_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 00:20:52 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/26 00:22:08 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	endgame(char *message, t_game *game, int i)
{
	if (i == -1)
	{
		printf("%s\n", message);
		destroy_image(game);
		exit(0);
		return ;
	}
	if (i == 2)
	{
		printf(RED"Error\n%s\n"ENDC, message);
		exit(1);
	}
	if (i == 3)
	{
		printf(RED"Error\n%s\n"ENDC, message);
		free(game->plot.temp);
		exit(1);
	}
	printf(RED"Error\n%s\n"ENDC, message);
	destroy_image(game);
	exit(1);
	return ;
}
