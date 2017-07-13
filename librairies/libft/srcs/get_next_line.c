/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:45:27 by vafanass          #+#    #+#             */
/*   Updated: 2016/12/20 22:11:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	is_newline(char **tab, char **line, int len)
{
	char	*leak;

	leak = *tab;
	*line = ft_strsub(*tab, 0, len);
	*tab = ft_strsub(*tab, len + 1, ft_strlen(*tab) - len);
	free(leak);
	return (1);
}

static int	read_file(int fd, char **line, char **tab)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		len;
	char	*leak;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		leak = *tab;
		*tab = ft_strjoin(*tab, buff);
		free(leak);
		len = find_nl(*tab);
		if (len > -1)
		{
			is_newline(tab, line, len);
			return (1);
		}
	}
	return (-3);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tab[4864];
	int				test;

	if (fd < 0 || fd == 1 || fd == 2 ||
			fd > 4864 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (tab[fd] == NULL)
		tab[fd] = ft_strnew(0);
	if (find_nl(tab[fd]) > -1)
		return (is_newline(&tab[fd], line, find_nl(tab[fd])));
	if ((test = read_file(fd, line, &tab[fd])) && test != -3)
		return (test);
	if (find_nl(tab[fd]) == -1 && ft_strlen(tab[fd]) > 0)
	{
		*line = ft_strsub(tab[fd], 0, ft_strlen(tab[fd]));
		tab[fd] = ft_strdup("");
		return (1);
	}
	return (0);
}
