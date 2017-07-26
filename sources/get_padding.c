/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:36:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 14:24:13 by vafanass         ###   ########.fr       */
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
		if (!(*flag & BYTE_A) && elem->info->name[0] == '.')
			elem = elem->next;
		else
		{
			if (get_int_len(elem->info->nb_link) > p->link)
				p->link = get_int_len(elem->info->nb_link);
			if ((int)ft_strlen(elem->info->owner) > p->user)
				p->user = ft_strlen(elem->info->owner);
			if ((int)ft_strlen(elem->info->group) > p->group)
				p->group = ft_strlen(elem->info->group);
			if (get_int_len(elem->info->size) > p->size)
				p->size = get_int_len(elem->info->size);
			if (get_int_len(elem->info->minor) > p->minor)
				p->minor = get_int_len(elem->info->minor);
			if (get_int_len(elem->info->major) > p->major)
				p->major = get_int_len(elem->info->major);
			if (*flag & BYTE_I)
			{
				if (get_int_len(elem->info->inode) > p->inode)
					p->inode = get_int_len(elem->info->inode);
			}
		elem = elem->next;
		}
	}
}