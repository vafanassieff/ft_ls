/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/19 22:03:48 by vafanass         ###   ########.fr       */
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

void	swap(t_elem **a, t_elem **b)
{
	t_info *temp;

	temp = (*a)->info;
	(*a)->info = (*b)->info;
	(*b)->info = temp;
}

void	sort_list(t_elem *lst, int len)
{
	t_elem *tmp;

	tmp = lst;
	while (len)
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->info->path, tmp->next->info->path) > 0)
				swap_info(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		tmp = lst;
		len--;
	}
}

int 	main(int argc, char **argv)
{
	unsigned int 	flag;
	t_list			list;
	int				nb;
	
	init(&flag, &list);
	get_arg(argc, argv, &flag, &list);
	nb = count_list(&list);
	sort_list(list.first, nb);
	
	printbits(flag); // Print flag value
	
	fill_arg(flag, &list);
	view_list(&list);
	free_list(&list);
	return(0);
}