#include "../includes/so_long.h"

void	map_maker(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			if (game->plot.map[y][x] == '1') //alterar [] []
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->floor.ptr,  (50 * x), (50 * y));
			else
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->wall.ptr,  (50 * x), (50 * y));
			x++;
		}
		y++;
	}
	return ;
}

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ; //verificar depois
	game->plot.temp = ft_strdup("");
	while ((game->plot.line = get_next_line(fd)))
	{
		if (!game->plot.line)
			break ;
		game->plot.temp = gnl_strjoin(game->plot.temp, game->plot.line);
		free(game->plot.line);
	}
	game->plot.map = ft_split(game->plot.temp, '\n');
	free(game->plot.temp);
	close(fd);
	return ;
}
