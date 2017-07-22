/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:30 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 00:22:44 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	permission_denied(t_info *info, char *path, t_list *cur)
{
	char *tmp;

	info = init_info();
	info->path = ft_strjoin(path, "/");
	tmp = ft_strdup("ft_ls : ");
	tmp = ft_strjoin(tmp, ft_strrchr(path, '/') + 1);
	tmp = ft_strjoin(tmp, ": Permissions denied");
	info->name = tmp;
	push_back(cur, info);
}

void	get_data(char *path, t_dirent *read, t_list *cur, t_info *info)
{
	t_stat 	s;
	char	*tmp;
	
	if (!info)
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

void	read_folder(t_list *cur, char *path)
{
	DIR			*folder;
	t_dirent	*read;
	t_info		*info;

	info = NULL;
	if (!(folder = opendir(path)))
	{
		permission_denied(info, path, cur);
		return;
	}
	while ((read = readdir(folder)) != NULL)
		get_data(path, read, cur, info);
	if (closedir(folder) == -1)
		get_perror(path, 1);
}