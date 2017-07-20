/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 18:09:41 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_folder(t_list *cur, char *path)
{
	DIR				*folder;
	struct	dirent	*read;
	t_info			*info;

	folder = opendir(path);
	while ((read = readdir(folder)) != NULL)
	{
		info = init_info();
		info->path = ft_strdup(path);
		info->name = ft_strdup(read->d_name);
		push_back(cur, info);
	}
	if (closedir(folder) == -1)
		get_perror(path, 1);
}

void	show_elem(t_list *l, unsigned int flag)
{
   t_elem *pelem = l->first;
   while(pelem)
   {
    ft_putendl(pelem->info->name);
     pelem = pelem->next;
   }
}

void 	fill_arg(unsigned int flag, t_list *l, int nb)
{

	t_list			cur;
	t_elem			*elem;

	cur.first = NULL;
	cur.last = NULL;
	elem = l->first;
	while(elem)
	{
		if(elem->info->is_dir == 1)
			read_folder(&cur, elem->info->path);
		else
			ft_putendl(elem->info->path);
		sort_list(cur.first, flag);
		if (nb > 1 && elem->info->is_dir == 1)
		{
			ft_putstr(elem->info->path);
			ft_putendl(":");
		}
		show_elem(&cur, flag);
		if (elem->next != NULL && elem->info->is_dir == 1)
			ft_putchar('\n');
		free_list(&cur);
		elem = elem->next;
	}
}

int 	main(int argc, char **argv)
{
	unsigned int 	flag;
	int				nb;
	t_list			list;
	
	init(&flag, &list);
	get_arg(argc, argv, &flag, &list);
	nb = count_list(list.first);
	verif_arg(&list);
	sort_list(list.first, flag);
	fill_arg(flag, &list, nb);
	free_list(&list);
	return(0);
}