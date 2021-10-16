/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/16 00:54:27 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_H
# define SO_UTILS_H

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
	int		bits_per_pixel;
	int		mem_po;
	int		endian;
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

//Estrutura geral
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
}	t_game;

# define UP          119
# define DOWN        115
# define LEFT        97
# define RIGHT       100
# define ESC         65307
# define KEYPRESS    2
# define KEYRELEASE  3

#endif