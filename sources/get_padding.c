/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:36:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 17:14:22 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_padding(t_padding *p, t_list *l, UINT *flag)
{
	t_elem	*elem;

	init_padding(p);
	elem = l->first;
	while (elem)
	{
		if (get_int_len(elem->info->nb_link) > p->link)
			p->link = get_int_len(elem->info->nb_link);
		if ((int)ft_strlen(elem->info->owner) > p->user)
			p->user = ft_strlen(elem->info->owner);
		if ((int)ft_strlen(elem->info->group) > p->group)
			p->group = ft_strlen(elem->info->group);
		if (get_int_len(elem->info->size) > p->size)
			p->size = get_int_len(elem->info->size);
		elem = elem->next;
	}
	if (*flag & BYTE_I)
		printf("toto");
}