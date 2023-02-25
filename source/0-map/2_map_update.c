/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:11:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/25 03:12:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void			read_map(t_game *game, int fd);
static t_counter	start_counter(char *string_map, t_game *game);
static void			count_elements(t_counter *cnt, char c);

void	init_map(t_game *game, char *path)
{
	int	fd;

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
	game->i = start_counter(temp, game);
	game->plot.map = ft_split(temp, '\n');
	free(temp);
	return ;
}

static t_counter	start_counter(char *string_map, t_game *game)
{
	t_counter	cnt;
	int			i;

	cnt = new_counter();
	i = 0;
	while (string_map[i] != '\0')
	{
		if (is_double_line(string_map, i))
		{
			free(string_map);
			endgame("Invalid, file!", game, file_error);
		}
		count_elements(&cnt, string_map[i]);
		i++;
	}
	is_elements_number_valid(game, &cnt, string_map);
	return (cnt);
}

static void	count_elements(t_counter *cnt, char c)
{
	if (c == 'C')
		cnt->collectible++;
	else if (c == 'E')
		cnt->exit++;
	else if (c == 'P')
		cnt->start++;
	else if (c == '0')
		cnt->empty++;
}
