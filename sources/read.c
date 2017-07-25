/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:30 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 13:33:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_link(t_info *info, t_stat *s)
{
	ssize_t	r;
	char 	*tmp;
	char	*tmp_name;

	tmp = ft_strjoin(info->path, info->name);
	tmp_name = ft_strdup(info->name);
	free(info->name);
	info->name = malloc(sizeof(char *) * (s->st_size + 1));
	if (info->name == NULL)
		exit(1);
	r = readlink(tmp, info->name, s->st_size);
	if (r == -1)
		get_perror("", 1);
	free(tmp);
	tmp = ft_strjoin(tmp_name, " -> ");
	free(tmp_name);
	tmp_name = ft_strdup(info->name);
	free(info->name);
	info->name = ft_strjoin(tmp, tmp_name);
	free(tmp);
	free(tmp_name);
}

void	get_long_data(t_info *info, UINT *flag, t_stat *s)
{
	info->type = get_type(s);
	if (info->type == 'l')
		get_link(info, s);
	if ((info->type == 'b') || (info->type == 'c'))
	{
		info->major = (int)major(s->st_rdev);
		info->minor = (int)minor(s->st_rdev);
	}
	info->mode = get_mode(s);
	info->owner = get_owner(s);
	info->group = get_group(s);
	info->size = (int)(s->st_size);
	get_time(s->st_mtime, &info->m_date);
	info->m_time = s->st_mtime;
	info->nb_link = (unsigned int)(s->st_nlink);
	info->block_size = (int)(s->st_blksize);
	info->nb_block = (int)(s->st_blocks);
	if (*flag &BYTE_I)
		info->inode = (int)(s->st_ino);
}

t_info	*get_data(char *path, char *name,UINT *flag, int code)
{
	t_stat 	s;
	char	*tmp;
	t_info	*info;

	info = init_info();
	info->name = ft_strdup(name);
	if (name[0] == '/')
		tmp = ft_strdup(name);
	else
	{
	if (ft_strcmp(path, name) == 0)
		info->path = ft_strdup("./");
	else
		info->path = ft_strjoin(path, "/");
	tmp = ft_strjoin(info->path,  info->name);
	}
	if ((lstat(tmp, &s) < 0) && code == 1)
		get_perror(info->name, 0);
	info->is_dir = get_dir(&s);
	if (*flag & BYTE_L)
		get_long_data(info, flag, &s);
	free(tmp);
	return(info);
}

void	read_folder(t_list *cur, char *path, UINT *flag)
{
	DIR			*folder;
	t_dirent	*read;
	t_info		*info;

	info = NULL;
	if (!(folder = opendir(path)))
	{
		permission_denied(path, cur);
		return;
	}
	while ((read = readdir(folder)) != NULL)
	{
		info = get_data(path, read->d_name, flag, 1);
		push_back(cur, info);
	}
	if (closedir(folder) == -1)
		get_perror(path, 1);
}