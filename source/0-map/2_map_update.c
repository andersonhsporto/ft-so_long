/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 02:36:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void			render_player(t_game *game);
static void			read_map(t_game *game, int fd);
static t_counter	start_counter(char *string_map, t_game *game, int i);

void	player_init(t_game	*game)
{
	t_point	point;

	point.y = 0;
	while (game->plot.map[point.y])
	{
		point.x = 0;
		while (game->plot.map[point.y][point.x])
		{
			if (game->plot.map[point.y][point.x] == 'P')
			{
				game->character.x = (SPRITE_SIZE * point.x);
				game->character.y = (SPRITE_SIZE * point.y);
				render_player(game);
				return ;
			}
			point.x++;
		}
		point.y++;
	}
	return ;
}

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character.ptr, game->character.x, game->character.y);
}

void	init_map(t_game *game, char *path)
{
	int		fd;

	fd = open_file(path);
	read_map(game, fd);
	game->plot.length = len_map_validation(game->plot.map, game);
	close(fd);
	return ;
}

static void	read_map(t_game *game, int fd)
{
	char	*temp;

	temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		temp = gnl_strjoinfree(temp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = start_counter(temp, game, 0);
	game->plot.map = ft_split(temp, '\n');
	free(temp);
	return ;
}

static t_counter	start_counter(char *string_map, t_game *game, int i)
{
	t_counter	cnt;

	cnt = new_counter();
	while (string_map[i] != '\0')
	{
		if ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])))
			endgame("Invalid, file!", game, file_error);
		if (string_map[i] == 'C')
			cnt.collectible++;
		else if (string_map[i] == 'E')
			cnt.exit++;
		else if (string_map[i] == 'P')
			cnt.start++;
		else if (string_map[i] == '0')
			cnt.empty++;
		i++;
	}
	if (!(cnt.collectible > 0 && cnt.exit == 1 && \
	cnt.start == 1 && cnt.empty > 0))
		endgame("Invalid, file!", game, file_error);
	return (cnt);
}
