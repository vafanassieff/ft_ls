/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:02:50 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 16:09:26 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*six_month(char *tmp)
{
	char	*year;
	char	*tmpbis;
	char	*tmpter;
	char	*toto;

	tmp[24] = '\0';
	toto = " ";
	year = ft_strsub(tmp, 20, 4);
	tmp = ft_strsub(tmp, 4, 20);
	tmpbis = ft_strsub(tmp, 0, 7);
	tmpter = ft_strjoin(tmpbis, toto);
	free(tmpbis);
	tmpbis = ft_strjoin(tmpter, year);
	free(tmp);
	free(year);
	free(tmpter);
	return (tmpbis);
}

static char	*time_noflag(char *tmp)
{
	char	*tmpbis;

	tmp[24] = '\0';
	tmp = ft_strsub(tmp, 4, 20);
	tmpbis = ft_strsub(tmp, 0, 12);
	free(tmp);
	return (tmpbis);
}

void		get_time(time_t mtime, char **date, UINT *flag)
{
	char	*tmp;
	time_t	current;

	tmp = ctime(&mtime);
	if (*flag & BYTE_BT)
	{
		tmp[24] = '\0';
		*date = ft_strdup(tmp);
	}
	else
	{
		current = time(0);
		if (mtime > current + 15638400 || current - mtime > 15638400)
			*date = six_month(tmp);
		else
			*date = time_noflag(tmp);
	}
}
