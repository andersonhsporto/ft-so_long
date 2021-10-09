/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:43:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/26 11:12:54 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count(char const *s, char c)
{
	size_t	check;
	size_t	words;

	check = 1;
	words = 0;
	while (*s)
	{
		if (*s == c)
			check = 1;
		else if (check == 1)
		{
			check = 0;
			words++;
		}
		s++;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\0') && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	array = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (array == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
			i = (i + ft_wordlen(&s[i], c) - 1);
			j++;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}
