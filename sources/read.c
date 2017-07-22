/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:30 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/22 18:46:09 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_data(char *path, struct	dirent	*read, t_list *cur)
{
	t_info			*info;
	struct 	stat 	s;
	char			*tmp;
	
	info = init_info();
	info->path = ft_strjoin(path, "/");
	info->name = ft_strdup(read->d_name);
	tmp = ft_strjoin(info->path,  info->name);
	if (stat(tmp, &s) < 0)
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
	DIR				*folder;
	struct	dirent	*read;

	folder = opendir(path);
	while ((read = readdir(folder)) != NULL)
		get_data(path, read, cur);
	if (closedir(folder) == -1)
		get_perror(path, 1);
}