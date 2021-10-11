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
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->wall.ptr,  (26 * x), (32 * y));
			else
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->floor.ptr,  (26 * x), (32 * y));
			x++;
		}
		y++;
	}
	return ;
}

int	len_map(char **map)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		j = ft_strlen(map[i]);
		if (k != j)
			return (0);
		i++;
	}
	return(k);
}

void	init_map(t_game *game, char *path)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ; //verificar depois
	game->plot.temp = ft_strdup("");
	i = 0;
	while ((game->plot.line = get_next_line(fd)))
	{
		if (!game->plot.line)
			break ;
		game->plot.temp = gnl_strjoin(game->plot.temp, game->plot.line);
		free(game->plot.line);
		i++;
	}
	game->plot.map = ft_split(game->plot.temp, '\n');
	game->plot.height = i;
	game->plot.length = len_map(game->plot.map);
	close(fd);
	return ;
}
