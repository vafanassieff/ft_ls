/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:29:09 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:45:13 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;
	void	*c;

	if (!(c = (void*)ft_memalloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		c = NULL;
		content_size = 0;
	}
	else
		c = ft_memcpy(c, content, content_size);
	if (!(newlst = (t_list*)malloc(sizeof(newlst) * content_size)))
		return (NULL);
	newlst->content = c;
	newlst->content_size = content_size;
	newlst->next = NULL;
	return (newlst);
}
