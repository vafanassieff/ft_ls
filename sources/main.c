/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/21 15:57:06 by vafanass         ###   ########.fr       */
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

void	show_file(t_list *arg_list, int nb)
{
	t_elem 	*tmp;
	t_elem	*remove;
	int 	i;

	tmp = arg_list->first;
	i = 0;
	while (tmp)
	{
		if(tmp->info->is_dir == 0)
		{
			ft_putendl(tmp->info->name);
			remove = tmp;
			tmp = tmp->next;
			remove_elem(remove, arg_list);
			i++;
		}
		else
			tmp = tmp->next;
	}
	if (i != nb)
		ft_putchar('\n');
}

void 	fill_arg(unsigned int flag, t_list *l, int nb)
{

	t_list			cur;
	t_elem			*arg;

	arg = l->first;
	while(arg)
	{
		cur.first = NULL;
		cur.last = NULL;
		read_folder(&cur, arg->info->path);
		if (nb > 1)
		{
			ft_putstr(arg->info->path);
			ft_putendl(":");
		}
		sort_list(cur.first, flag);
		show_elem(&cur, flag);
		if (arg->next != NULL)
			ft_putchar('\n');
		free_list(&cur);
		arg = arg->next;
	}
}

int 	main(int argc, char **argv)
{
	unsigned int 	flag;
	int				nb;
	t_list			arg_list;
	
	init(&flag, &arg_list);
	get_arg(argc, argv, &flag, &arg_list);
	nb = count_list(arg_list.first);
	sort_list(arg_list.first, flag);
	verif_arg(&arg_list);
	show_file(&arg_list, nb);
	fill_arg(flag, &arg_list, nb);
	free_list(&arg_list);
	return(0);
}