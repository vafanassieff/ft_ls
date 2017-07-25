/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:29:02 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 15:08:43 by vafanass         ###   ########.fr       */
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