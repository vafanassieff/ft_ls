/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:51:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 16:33:06 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*init_info()
{
	t_info *info;
	
	info = malloc(sizeof(t_info));
	if (!info)
		exit(0);
	info->path = NULL;
	info->name = NULL;
	info->mode = NULL;
	info->owner = NULL;
	info->group = NULL;
	info->m_date = NULL;
	info->size = 0;
	info->inode = 0;
	info->m_date = NULL;
	info->m_time = 0;
	info->nb_link = 0;
	info->block_size = 0;
	info->nb_block = 0;
	info->major = 0;
	info->minor = 0;
	return (info);
}

void	init_padding(t_padding *p)
{
	p->link = 0;
	p->user = 0;
	p->group = 0;
	p->size = 0;
}

void	init(UINT *flag, t_list *l)
{
   	l->first = NULL;
   	l->last = NULL;
	*flag = 0;
}