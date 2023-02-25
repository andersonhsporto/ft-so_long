/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:05:39 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_utils.h"

# include "../libft/libft.h"
# include "../gnl/get_next_line_bonus.h"
# include "mlx.h"

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool

void		map_maker(t_game	*game);
void		init_map(t_game *game, char *path);

int			key_check(int keycode, t_game *game);
void		print_moves(t_game *game);

void		move_right(t_game *parameter);
void		move_left(t_game *parameter);
void		move_up(t_game *parameter);
void		move_down(t_game *parameter);

void		player_init(t_game	*game);
int			len_map_validation(char **map, t_game *game);

void		init_so_long(t_game *game);
void		init_images(t_game	*game);
t_img		new_sprite(void *mlx, char *path);
void		destroy_image(t_game *game);
void		free_map(t_game	*game);

int			red_cross(t_game *game);
int			mini_maker(t_game *game);
void		endgame(char *message, t_game *game, enum e_state i);

t_point		get_screen_size(t_game *game);
bool		is_larger_than_window(t_game *game);

bool		is_surrounded_by_trees(t_game *game, int y, int x);
bool		is_rectangular(t_game *game);
bool		is_valid_character(t_game *game, int y, int x);

int			open_file(char *path);
t_counter	new_counter(void);
#endif