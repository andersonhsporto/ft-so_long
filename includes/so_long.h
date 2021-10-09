/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/09 01:22:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_utils.h"

# include "../mlx/mlx.h"

# include "../libft/libft.h"

# include <stdio.h>

# include <X11/X.h>

# include <string.h>
# include <stdlib.h>

void	init_images(t_game	*game);
void	init_so_long(t_game *teste);
void	map_maker(t_game	*game);
int		key_check(int keycode, t_game *parameter);
t_img	ft_new_sprite(void *mlx, char *path);

void	move_right(t_game *parameter);
void	move_left(t_game *parameter);
void	move_up(t_game *parameter);
void	move_down(t_game *parameter);

int		check_wall(t_game *parameter);

#endif