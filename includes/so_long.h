#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_utils.h"

# include "../mlx/mlx.h"

# include "../libft/libft.h"

# include <stdio.h>

# include <X11/X.h>

# include <math.h>

#include <string.h>
#include <stdlib.h>

void	init_images(t_game	*game);
void	init_so_long(t_game *teste);
int		key_check(int keycode, t_game *parameter);
t_img	ft_new_sprite(void *mlx, char *path);
void	map_maker(t_game	*game);

#endif