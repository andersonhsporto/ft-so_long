/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:13:55 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/27 22:17:31 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstring;
	size_t	i;
	size_t	j;

	if (s1 == 0)
		return ((char *)s2);
	if (s2 == 0)
		return ((char *)s1);
	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstring == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		nstring[i + j] = s2[j];
		j++;
	}
	nstring[i + j] = '\0';
	return (nstring);
}
