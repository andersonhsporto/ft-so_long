/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:20:26 by anhigo-s          #+#    #+#             */
/*   Updated: 2024/06/01 19:38:21 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_file(char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
		print_exit_err_message("Invalid file");
	return (fd);
}

t_counter	new_counter(void)
{
	t_counter	counter;

	counter.collectible = 0;
	counter.start = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.empty = 0;
	return (counter);
}

int str_array_len(char **array)
{
	int i;

	i = 0;
	while (array[i]) {
		printf("%s\n", array[i]);
		i++;
	}
	return (i);
}
