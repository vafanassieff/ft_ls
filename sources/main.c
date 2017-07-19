/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/19 15:33:25 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	info->path = "./";
	info->type = 0;
	return(info);
}

void	init(unsigned int *flag, t_list *l)
{
   	l->first = NULL;
   	l->last = NULL;
	*flag = 0;
}

int 	main(int argc, char **argv)
{
	unsigned int 	flag;
	t_list			list;

	init(&flag, &list);
	get_arg(argc, argv, &flag, &list);
	
	printbits(flag);
	view_list(list);
	return(0);
}