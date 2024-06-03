/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:26:58 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 19:38:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void			read_map(t_game *game, int fd);
static t_counter	start_counter(const char *string_map);
static void			count_elements(t_counter *cnt, char c);
static char			*file_to_string(int fd);

void	init_map(t_game *game, char *path)
{
	const int	fd = open_file(path);

	read_map(game, fd);
	close(fd);
	return ;
}

static void	read_map(t_game *game, int fd)
{
	const char	*string_map = file_to_string(fd);
	char		**map;

	if (is_double_line(string_map))
	{
		free(((char *)string_map));
		endgame("Invalid file: double line!", game, error);
	}
	map = ft_split(string_map, '\n');
	game->i = start_counter(string_map);
	free(((char *)string_map));
	game->plot.map = map;
	game->plot.height = str_array_len(map);
	game->plot.length = ft_strlen(map[0]);
	return ;
}

static char	*file_to_string(int fd)
{
	char	*temp;
	char	*line;

	temp = ft_strdup("");
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = gnl_strjoinfree(temp, line);
		free(line);
	}
	free(line);
	return (temp);
}

static t_counter	start_counter(const char *string_map)
{
	t_counter	cnt;
	int			i;

	cnt = new_counter();
	i = 0;
	while (string_map[i] != '\0')
	{
		count_elements(&cnt, string_map[i]);
		i++;
	}
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
