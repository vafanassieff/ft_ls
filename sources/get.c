/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:29:02 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/24 13:29:49 by vafanass         ###   ########.fr       */
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