/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:30 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 02:00:20 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"	

void 	remove_point(t_list *l)
{
	t_elem	*tmp;
	t_elem	*remove;

	tmp = l->first;
	while (tmp)
	{
	 	if (tmp->info->name[0] == '.')
		{
			remove = tmp;
			tmp = tmp->next;
			remove_elem(remove, l);
		}
		else
			tmp = tmp->next;
	}
}

void	get_data(char *path, t_dirent *read, t_list *cur, UINT *flag)
{
	t_stat 	s;
	char	*tmp;
	t_info	*info;

	info = init_info();
	info->path = ft_strjoin(path, "/");
	info->name = ft_strdup(read->d_name);
	tmp = ft_strjoin(info->path,  info->name);
	if (lstat(tmp, &s) < 0)
		get_perror(info->name, 0);
	if (S_ISDIR(s.st_mode))
		info->is_dir = 1;
	else
		info->is_dir = 0;
	push_back(cur, info);
	free(tmp);
}

void	read_folder(t_list *cur, char *path, UINT *flag)
{
	DIR			*folder;
	t_dirent	*read;

	if (!(folder = opendir(path)))
	{
		permission_denied(path, cur);
		return;
	}
	while ((read = readdir(folder)) != NULL)
		get_data(path, read, cur, flag);
	if (closedir(folder) == -1)
		get_perror(path, 1);
	//if (!(*flag & BYTE_A))
	//	remove_point(cur);
}