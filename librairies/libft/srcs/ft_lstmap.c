/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:19:10 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:45:06 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_list;

	if (!lst || !f)
		return (NULL);
	if (!lst->next)
		return (f(lst));
	n_list = ft_lstmap(lst->next, f);
	ft_lstadd(&n_list, f(lst));
	return (n_list);
}
