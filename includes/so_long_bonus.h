/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/26 00:18:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_utils_bonus.h"

# include "../0-libft/libft.h"
# include "mlx.h"

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool
# include <time.h>//bonus delay

void	render_map(t_game	*game);
void	init_map(t_game *game, char *path);

int		key_check(int keycode, t_game *game);
void	print_moves(t_game *game);

void	move_right(t_game *parameter);
void	move_left(t_game *parameter);
void	move_up(t_game *parameter);
void	move_down(t_game *parameter);

void	player_init(t_game	*game);
int		len_map_validation(char **map, t_game *game);

void	init_so_long(t_game *game);
void	init_images(t_game	*game);
t_img	new_sprite(void *mlx, char *path);
void	destroy_image(t_game *game);
void	free_map(t_game	*game);

int		red_cross(t_game *game);
int		mini_maker(t_game *game);
void	endgame(char *message, t_game *game, int i);
int		check_arg(const char *argv);

int		fix_image(t_game *game);

void	init_sprites(t_game	*game);
int		fix_pos(int keycode, t_game *game);
void	put_image(t_game *game, void *frame);

void	print_map_string(t_game *game);
void	print_potion(t_game *game, int y, int x);

void	print_e(t_game *game, int y, int x);
void	init_enemies(t_game *game, int i, int j);
void	destroy_enemies(t_game *game);

void	init_collec(t_game *game, int i, int j);

void	delay(int milliseconds);

void	init_link_down(t_game *game, int i, int j);
void	init_link_right(t_game *game, int i, int j);
void	init_link_left(t_game *game, int i, int j);
void	init_link_up(t_game *game, int i, int j);
void	init_collec(t_game *game, int i, int j);

void	print_portal(t_game *game);
#endif