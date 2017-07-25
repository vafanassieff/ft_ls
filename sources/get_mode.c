/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:08:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 15:17:03 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_setuid(t_stat *sb)
{
	char	setuid;

	if (sb->st_mode & S_IXUSR)
		setuid = 'x';
	else
		setuid = '-';
	if (sb->st_mode & S_ISUID)
	{
		if (sb->st_mode & 0100)
			setuid = 's';
		else
			setuid = 'S';
	}
	return (setuid);
}

static char	get_setgid(t_stat *sb)
{
	char	setgid;

	if (sb->st_mode & S_IXGRP)
		setgid = 'x';
	else
		setgid = '-';
	if (sb->st_mode & S_ISGID)
	{
		if (sb->st_mode & 0010)
			setgid = 's';
		else
			setgid = 'S';
	}
	return (setgid);
}

static char	get_sticky(t_stat *sb)
{
	char	sticky;

	if (sb->st_mode & S_IXOTH)
		sticky = 'x';
	else
		sticky = '-';
	if (sb->st_mode & S_ISVTX)
	{
		if (sb->st_mode & 0100)
			sticky = 't';
		else
			sticky = 'T';
	}
	return (sticky);
}

char	*get_mode(t_stat *s)
{
	char	*mode;

	mode = ft_strnew(10);
	mode[0] = (s->st_mode & S_IRUSR) ? 'r' : '-';
    mode[1] = (s->st_mode & S_IWUSR) ? 'w' : '-';
    mode[2] = get_setuid(s);
    mode[3] = (s->st_mode & S_IRGRP) ? 'r' : '-';
    mode[4] = (s->st_mode & S_IWGRP) ? 'w' : '-';
    mode[5] = get_setgid(s);
    mode[6] = (s->st_mode & S_IROTH) ? 'r' : '-';
    mode[7] = (s->st_mode & S_IWOTH) ? 'w' : '-';
    mode[8] = get_sticky(s);
	mode[9] = '\0';
	return (mode);
}