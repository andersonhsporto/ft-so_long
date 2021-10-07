#ifndef SO_UTILS_H
# define SO_UTILS_H

typedef struct	s_img
{
	void	*ptr;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		x;
	int		y;
}				t_img;

//Estrutura geral

typedef struct	s_game
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	*map;
	t_img	character;
	t_img	floor;
	t_img	wall;
}	t_game;

#define	UP          119
#define	DOWN        115
#define	LEFT        97
#define	RIGHT       100
#define ESC         65307
#define KeyPress    2
#define KeyRelease  3

#endif