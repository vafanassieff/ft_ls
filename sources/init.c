/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:51:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 12:51:37 by vafanass         ###   ########.fr       */
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
	info->type = 0;
	return (info);
}

void	init(unsigned int *flag, t_list *l)
{
   	l->first = NULL;
   	l->last = NULL;
	*flag = 0;
}