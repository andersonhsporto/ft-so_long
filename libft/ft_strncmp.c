/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:57:02 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/10 20:47:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2) && (i < n - 1))
	{
		s1++;
		s2++;
		i++;
	}
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
