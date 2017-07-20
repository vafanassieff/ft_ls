/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 13:47:51 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_folder(t_list *cur, char *path)
{
	DIR				*folder;
	struct	dirent	*read;
	t_info			*info;
	struct	stat	sb;

/*	stat(path,&sb);
	if ((sb.st_mode & S_IFMT) == S_IFREG)
	{	
		ft_putstr(path);
		return;
	}*/
	folder = opendir(path);
	if (!folder)
	{
		open_error(path);
		return ;
	}
	while ((read = readdir(folder)) != NULL)
	{
		info = init_info();
		info->path = ft_strdup(path);
		info->name = ft_strdup(read->d_name);
		push_back(cur, info);
	}
	if (closedir(folder) == -1)
		exit(-1);
}

void 	fill_arg(unsigned int flag, t_list *l)
{

	t_list			cur;
	t_elem			*elem;

	cur.first = NULL;
	cur.last = NULL;
	elem = l->first;
	while(elem)
	{
		read_folder(&cur, elem->info->path);
		elem = elem->next;
		//view_list(&cur);
		free_list(&cur);
	}
}

void	verif_arg(t_list *l)
{
	t_elem	*tmp;
	t_elem	*remove;
	
	tmp = l->first;
	while (tmp)
	{
		if (ft_strcmp(tmp->info->path,"b") == 0)
		{
			remove = tmp;
			tmp = tmp->next;
			remove_elem(remove, l);
		}
		else
			tmp = tmp->next;
	}
}

int 	main(int argc, char **argv)
{
	unsigned int 	flag;
	t_list			list;
	
	init(&flag, &list);
	get_arg(argc, argv, &flag, &list);
	sort_list_ascii(list.first);
	verif_arg(&list);

	printbits(flag); // Print flag value
	
	//fill_arg(flag, &list);
	view_list(&list);
	free_list(&list);
	while(1);
	return(0);
}