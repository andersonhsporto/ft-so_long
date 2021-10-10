/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:19:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/10 00:05:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_H
# define SO_UTILS_H

typedef struct s_img
{
	void	*ptr;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		x;
	int		y;
}	t_img;

//Estrutura geral
typedef struct s_game
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	**map;
	t_img	character;
	t_img	character_d2;
	t_img	character_l;
	t_img	character_l2;
	t_img	character_l3;
	t_img	character_r;
	t_img	character_r2;
	t_img	character_u;
	t_img	character_u2;
	t_img	floor;
	t_img	wall;
}	t_game;

typedef struct s_draw
{
	char	*line;
	char	*temp;
}	t_draw;



# define UP          119
# define DOWN        115
# define LEFT        97
# define RIGHT       100
# define ESC         65307
# define KEYPRESS    2
# define KEYRELEASE  3

#endif