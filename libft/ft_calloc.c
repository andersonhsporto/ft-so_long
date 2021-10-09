/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:03:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/09/12 12:03:06 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*pointer;
	size_t			i;

	pointer = malloc(count * size);
	if (pointer == 0)
	{
		return (0);
	}
	else
	{
		i = 0;
		while (i < (count * size))
		{
			pointer[i] = '\0';
			i++;
		}
	}
	return ((void *)pointer);
}
