/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:25 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/15 22:43:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	red_cross(t_game *game)
{
	endgame("", game, -1);
	return(0);
}

void	endgame(char *message, t_game *game, int i)
{
	if (i == -1)
	{
		printf("%s\n", message);
		destroy_image(game);
		exit(0);
		return ;
	}
	printf("Error\n%s\n", message);
	exit(1);
	return ;
}

int	check_arg(const char	*argv)
{
	size_t	len;
	char *	string;

	len = 0;
	if ((string = ft_strrchr(argv, '.')))
	{
		len = ft_strlen(string);
		if (ft_memcmp(string, ".ber", len) == 0)
			return(1);
	}
	return (0);
}
