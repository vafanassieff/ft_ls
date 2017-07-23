/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:30 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 19:54:59 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"	

int		get_dir(t_stat *s)
{
	if (S_ISDIR(s->st_mode))
		return(1);
	else
		return(0);
}

char	get_type(t_stat	*s)
{
	if (S_ISDIR(s->st_mode))
		return('d');
	else if (S_ISLNK(s->st_mode))
		return('l');
	else if (S_ISCHR(s->st_mode))
		return('c');
	else if (S_ISBLK(s->st_mode))
		return('b');
	else if (S_ISFIFO(s->st_mode))
		return('p');
	else if (S_ISSOCK(s->st_mode))
		return('s');
	else
		return('-');
}

char	*get_mode(t_stat *s)
{
	char	*mode;

	mode = ft_strnew(10);
	mode[0] = (s->st_mode & S_IRUSR) ? 'r' : '-';
    mode[1] = (s->st_mode & S_IWUSR) ? 'w' : '-';
    mode[2] = (s->st_mode & S_IXUSR) ? 'x' : '-';
    mode[3] = (s->st_mode & S_IRGRP) ? 'r' : '-';
    mode[4] = (s->st_mode & S_IWGRP) ? 'w' : '-';
    mode[5] = (s->st_mode & S_IXGRP) ? 'x' : '-';
    mode[6] = (s->st_mode & S_IROTH) ? 'r' : '-';
    mode[7] = (s->st_mode & S_IWOTH) ? 'w' : '-';
    mode[8] = (s->st_mode & S_IXOTH) ? 'x' : '-';
	mode[9] = '\0';
	return (mode);
}

char	*get_owner(t_stat *s)
{
	t_passwd	*tmp;

	tmp = getpwuid(s->st_uid);
	return(tmp->pw_name);
}

char	*get_group(t_stat *s)
{
	t_group 	*tmp;

	tmp = getgrgid(s->st_gid);
	return(tmp->gr_name);
}

t_info	*get_data(char *path, char *name,UINT *flag)
{
	t_stat 	s;
	char	*tmp;
	t_info	*info;

	info = init_info();
	if (ft_strcmp(path, name) == 0)
		info->path = ft_strdup("./");
	else
		info->path = ft_strjoin(path, "/");
	info->name = ft_strdup(name);
	tmp = ft_strjoin(info->path,  info->name);
	if (lstat(tmp, &s) < 0)
		get_perror(info->name, 0);
	info->is_dir = get_dir(&s);
	info->type = get_type(&s);
	info->mode = get_mode(&s);
	info->owner = get_owner(&s);
	info->group = get_group(&s);
	info->size = (int)(s.st_size);
	info->inode = (int)(s.st_ino);
	info->m_date = ctime(&s.st_mtime);
	info->m_date[24] = '\0';
	info->m_time = s.st_mtime;
	info->nb_link = (unsigned int)(s.st_nlink);
	info->block_size = (int)(s.st_blksize);
	info->nb_block = (int)(s.st_blocks);
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
		info = get_data(path, read->d_name, flag);
		push_back(cur, info);
	}
	if (closedir(folder) == -1)
		get_perror(path, 1);
}