/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 18:27:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_H
# define SO_UTILS_H

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define WINDOW_NAME	"./so_long"
# define SPRITE_SIZE	32

# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define EXPOSE		12

# define KEY_RELEASE_MASK	2
# define NO_EVENT_MASK		0
# define EXPOSURE_MASK		32768

enum e_direction
{
	down,
	left,
	right,
	up,
};

enum e_state
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
	image_init = 5,
};

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
}	t_counter;

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;
}	t_draw;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	i;
	t_draw		plot;
	t_img		character;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		portal;
	int			state;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif