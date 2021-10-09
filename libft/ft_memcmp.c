/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 22:39:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/05 14:20:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			i;

	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	if (s1 == 0 && s2 == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (mem1[i] != mem2[i])
		{
			return (mem1[i] - mem2[i]);
		}
		i++;
	}
	return (0);
}
