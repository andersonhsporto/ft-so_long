/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/21 22:14:31 by anhigo-s         ###   ########.fr       */
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

enum e_direction
{
	down,
	left,
	right,
	up,
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
}	t_game;



#endif