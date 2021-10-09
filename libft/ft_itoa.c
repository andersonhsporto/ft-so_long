/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:55:22 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/09/08 22:16:45 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_decimal(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static char	*ft_printitoa(int n, char *str, size_t len)
{
	if (n == 0)
	{
		str[0] = '0';
	}
	else if (len == 1)
	{
		str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long int	num;

	num = n;
	len = 0;
	if (num < 0)
	{
		num = (num * -1);
		len = 1;
	}
	len = len + ft_decimal(n);
	str = malloc((len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	while (num > 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (ft_printitoa(n, str, len));
}
