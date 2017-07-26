/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 16:19:04 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 15:05:48 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	fill_arg(UINT *flag, t_list *l, int nb)
{
	t_list			cur;
	t_elem			*arg;

	arg = l->first;
	while(arg)
	{
		cur.first = NULL;
		cur.last = NULL;
		if (nb > 1)
		{
			ft_putstr(arg->info->name);
			ft_putendl(":");
		}
		read_folder(&cur, arg->info->path, flag);
		sort_list(cur.first, flag);
		show_elem(&cur, flag);
		if (arg->next != NULL && !(*flag & BYTE_R))
			ft_putchar('\n');
		if (*flag & BYTE_R)
			recursive(flag, &cur, cur.last);
		free_list(&cur);
		arg = arg->next;
	}
}

void	get_arg(int argc, char ** argv, UINT *flag, t_list *list)
{
	int 	i;
	int		test;
	t_info	*info;

	i = 0;
	test = FALSE;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1])
			add_flag(flag, argv[i]);
		else
			break;
	}
	while (i < argc)
	{
		info = get_data(argv[i], argv[i], flag, 0);
		push_back(list, info);
		i++;
		test = TRUE;
	}
	if (test != TRUE)
	{
		info = get_data(".", ".", flag, 0);
		push_back(list, info);
	}
}

void	verif_arg(t_list *l, UINT *flag)
{
	t_elem	*tmp;
	t_elem	*remove;
	t_stat 	s;
	char	*join;

	tmp = l->first;
	while (tmp)
	{
		if (ft_strcmp(tmp->info->name, "") == 0)
			error_fts_open();
		else if (lstat(tmp->info->name,&s) < 0)
		{
			get_perror(tmp->info->name, 0);
			remove = tmp;
			tmp = tmp->next;
			remove_elem(remove, l);
		}
		else
		{
			if (S_ISDIR(s.st_mode) && !(*flag & BYTE_D))
			{
				tmp->info->is_dir = 1;
				if (ft_strcmp(tmp->info->name, ".") != 0 && ft_strcmp(tmp->info->name, "./") != 0 && tmp->info->name[0] != '/')
				{
					join = ft_strjoin(tmp->info->path, tmp->info->name);
					free(tmp->info->path);
					tmp->info->path = ft_strdup(join);
					free(join);
				}
				else
				{
					free(tmp->info->path);
					tmp->info->path = ft_strdup(tmp->info->name);
				}
			}
			else
				tmp->info->is_dir = 0;
			tmp = tmp->next;
		}
	}
}