/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:15:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/24 22:20:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	i;

	string = malloc(ft_strlen(s1) + 1);
	if (string == 0)
		return (0);
	else
	{
		i = 0;
		while (i < (ft_strlen (s1) + 1))
		{
			string[i] = s1[i];
			i++;
		}
	}
	return (string);
}
