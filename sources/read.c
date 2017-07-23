/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:30 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 16:02:37 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"	

void	get_dir(t_stat *s, int *type)
{
	if (S_ISDIR(s->st_mode))
		*type = 1;
	else
		*type = 0;
}

void	get_type(t_stat	*s, char *type)
{
	if (S_ISDIR(s->st_mode))
		*type = 'd';
	else
		*type = '-';
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
	get_dir(&s, &info->is_dir);
	get_type(&s, &info->type);
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
}