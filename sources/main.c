/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 18:49:53 by vafanass         ###   ########.fr       */
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
	   if (pelem->info->name[0] != '.')
   	 		ft_putendl(pelem->info->name);
     pelem = pelem->next;
   }
}
void	show_file(t_elem *first)
{
	t_elem 	*tmp;
	int 	i;

	tmp = first;
	i = 0;
	while (tmp)
	{
		if(tmp->info->is_dir == 0)
		{
			ft_putendl(tmp->info->name);
			i++;
		}
		tmp = tmp->next;
	}
	if (i > 0)
		ft_putchar('\n');
}

void 	fill_arg(unsigned int flag, t_list *l, int nb)
{

	t_list			cur;
	t_elem			*elem;

	cur.first = NULL;
	cur.last = NULL;
	elem = l->first;
	show_file(elem);
	while(elem)
	{
		if(elem->info->is_dir == 1)
			read_folder(&cur, elem->info->path);
		if (nb > 1 && elem->info->is_dir == 1)
		{
			ft_putstr(elem->info->path);
			ft_putendl(":");
		}
		sort_list(cur.first, flag);
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