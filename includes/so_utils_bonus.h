/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/26 00:17:20 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_BONUS_H
# define SO_UTILS_BONUS_H

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define SPEED	5
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"

# define WINDOW_NAME	"./so_long_bonus"
# define SPRITE_SIZE	32

# define KEY_PRESS	2
# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define EXPOSE		12

# define KEY_PRESS_MASK		1
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
};

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
	int		time;
}	t_counter;

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
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
	char	*temp;
}	t_draw;

typedef struct s_frames
{
	void	*frame0;
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	void	*frame6;
	void	*frame7;
	void	*frame8;
	void	*frame9;
}	t_frames;

typedef struct s_emydata
{
	int			direction;
	int			collectible;
	int			exit;
	int			start;
	int			movements;
	t_frames	enemy_a;
}	t_emydata;

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
	t_frames	portal_a;
	t_frames	down_a;
	t_frames	left_a;
	t_frames	right_a;
	t_frames	up_a;
	t_frames	collect_a;
	t_emydata	public;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif