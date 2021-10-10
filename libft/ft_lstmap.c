/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 02:26:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/19 15:22:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*last;

	newlist = NULL;
	last = NULL;
	while (head)
	{
		if (newlist == NULL)
		{
			newlist = ft_lstnew(((*f)(head->content)));
			if (newlist == NULL)
				ft_lstdelone(newlist, del);
			last = ft_lstlast(newlist);
		}
		else
		{
			last->next = ft_lstnew(newlist);
			last = last->next;
			last->content = ((*f)(head->content));
			last->next = 0;
		}
		head = head->next;
	}
	return (newlist);
}
