/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:51:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/24 16:15:17 by vafanass         ###   ########.fr       */
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
	return (info);
}

void	init(UINT *flag, t_list *l)
{
   	l->first = NULL;
   	l->last = NULL;
	*flag = 0;
}