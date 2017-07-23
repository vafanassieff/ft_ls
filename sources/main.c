/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 16:03:30 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//TO DO LIST

// REMOVE LASY \N
// FASTER SORT

void 	fill_arg(UINT *flag, t_list *l, int nb)
{
	t_list			cur;
	t_elem			*arg;

	arg = l->first;
	while(arg)
	{
		cur.first = NULL;
		cur.last = NULL;
		read_folder(&cur, arg->info->path, flag);
		if (nb > 1)
		{
			ft_putstr(arg->info->path);
			ft_putendl(":");
		}
		sort_list(cur.first, flag);
		show_elem(&cur, flag);
		if (arg->next != NULL || *flag & BYTE_R)
			ft_putchar('\n');
		if (*flag & BYTE_R)
			recursive(flag, &cur);
		free_list(&cur);
		arg = arg->next;
	}
}

int 	main(int argc, char **argv)
{
	int			nb;
	UINT 		flag;
	t_list		arg_list;
	
	init(&flag, &arg_list);
	get_arg(argc, argv, &flag, &arg_list);
	count_list(arg_list.first, &nb);
	sort_list(arg_list.first, &flag);
	verif_arg(&arg_list);
	show_file(&arg_list, nb);
	fill_arg(&flag, &arg_list, nb);
	free_list(&arg_list);
	return(0);
}