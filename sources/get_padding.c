/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:36:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 17:49:01 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	padding_next(t_padding *p, t_elem *elem, UINT *flag)
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
	if ((int)ft_strlen(elem->info->name) > p->name)
		p->name = ft_strlen(elem->info->name);
	if (*flag & BYTE_I)
	{
		if (get_int_len(elem->info->inode) > p->inode)
			p->inode = get_int_len(elem->info->inode);
	}
}

void	get_padding(t_padding *p, t_list *l, UINT *flag)
{
	t_elem			*elem;
	struct winsize	size;

	init_padding(p);
	elem = l->first;
	if (ioctl(0, TIOCGWINSZ, (char *)&size) < 0)
		exit(-1);
	p->col = size.ws_col;
	while (elem)
	{
		if (!(*flag & BYTE_A) && elem->info->name[0] == '.')
			elem = elem->next;
		else
		{
			padding_next(p, elem, flag);
			elem = elem->next;
		}
	}
}
