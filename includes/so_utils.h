#ifndef SO_UTILS_H
# define SO_UTILS_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_image
{
	void      *pointer;
	t_vector  vector;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;

typedef struct s_game
{
	void	*mlx;
	void	*window_pointer;
	char	*map;
	int		keycode;
	int     up, down, left, right;
	t_image	img;
	t_vector  vector;
}	t_game;





#define	UP          119
#define	DOWN        115
#define	LEFT        97
#define	RIGHT       100
#define ESC         65307
#define KeyPress    2
#define KeyRelease  3

#endif