#include "./includes/so_long.h"

typedef struct 	s_data
{
	void    *mlx;
	void    *mlx_win;
	int     width, height;
	int     x, y;
	int     up, down, left, right;
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

  dst = data->addr
      + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

int ft_move(t_data *data)
{
  if (data->left == 1 && data->x > 0)
  {
    data->x -= 3;
    printf("x = %d, y= %d\n", data->x, data->y);
  }
  if (data->right == 1 && data->x + 100 < data->width)
  {
    data->x += 3;
    printf("x = %d, y= %d\n", data->x, data->y);
  }
  if (data->up == 1 && data->y > 0)
  {
    data->y -= 3;
    printf("x = %d, y= %d\n", data->x, data->y);
  }
  if (data->down == 1 && data->y + 100 < data->height)
  {
    data->y += 3;
    printf("x = %d, y= %d\n", data->x, data->y);
  }
  return (0);
}

int ft_key_press(int keycode, t_data *data)
{
  if (keycode == ESC)
  {
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
  }
  if (keycode == LEFT)
    data->left = 1;
  if (keycode == RIGHT)
    data->right = 1;
  if (keycode == UP)
    data->up = 1;
  if (keycode == DOWN)
    data->down = 1;
  return (0);
}

int ft_key_release(int keycode, t_data *data)
{
  if (keycode == LEFT)
    data->left = 0;
  if (keycode == RIGHT)
    data->right = 0;
  if (keycode == UP)
    data->up = 0;
  if (keycode == DOWN)
    data->down = 0;
  return (0);
}

int ft_draw(t_data *data)
{
//	printf("ft_draw!\n");
  int i;
  int j;
  int k;
  int x = data->x;
  int y = data->y;

  for (i = 0; i < data->width; i++)
  {
    for (j = 0; j < data->height; j++)
      my_mlx_pixel_put(data, i, j, 0x00008000);
  }
  for (i = x, k = 99; i < x + 50; i++, k -= 2)
  {
    for (j = y + k; j < y + 100; j++)
      my_mlx_pixel_put(data, i, j, 0x0000FF00);
  }
  for (i = x + 50, k = 0; i < x + 100; i++, k += 2)
  {
    for (j = y + k; j < y + 100; j++)
      my_mlx_pixel_put(data, i, j, 0x0000FF00);
  }
  mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
  return (0);
}

int main_loop(t_data *data)
{
	ft_draw(data);
	ft_move(data);
	return (0);
}

int main(void)
{
  t_data  data;

  data.mlx = mlx_init();
  data.width = 600;
  data.height = 400;
  data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "TESTE");
  data.img = mlx_new_image(data.mlx, 600, 400);
  data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

  mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
  data.x = 250;
  data.y = 150;
  mlx_hook(data.mlx_win, KeyPress, 1L<<0, ft_key_press, &data);
  mlx_hook(data.mlx_win, KeyRelease, 1L<<1, ft_key_release, &data);
  mlx_loop_hook(data.mlx, main_loop, &data);
  mlx_loop(data.mlx);
  return (0);
}
