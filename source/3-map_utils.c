/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:20:26 by anhigo-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:27:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nInvalid file\n");
		exit(1);
	}
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
