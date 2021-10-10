#include "../includes/so_long.h"

void	map_maker(t_game	*game)
{
	int i;

	i = 0;
	while(game->map[i])
	{
		if (game->map[i][i] == '1') //alterar [] []
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->floor.ptr,  (50 * i), 0);
		else
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->wall.ptr,  (50 * i), 0);
		i++;
	}
	return ;
}

void	init_map(t_game *game, char *path)
{
	t_draw	plot;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ; //verificar depois
	plot.temp = ft_strdup("");
	while ((plot.line = get_next_line(fd)))
	{
		if (!plot.line)
			break ;
		plot.temp = gnl_strjoin(plot.temp, plot.line);
		free(plot.line);
	}
	game->map = ft_split(plot.temp, '\n');
	free(plot.temp);
	close(fd);
	return ;
}

