/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:03:20 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/24 16:22:40 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	error_opt(char opt)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(opt);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-");
	ft_putstr(OPT_LIST);
	ft_putstr("] [file ...]");
	ft_putchar('\n');
	exit(1);
}

void	get_perror(char *str, int close)
{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		if (close == TRUE)
			exit(1);
}

void	error_fts_open()
{
	ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
	exit(1);
}

void	permission_denied(char *path, t_list *cur)
{
	t_info	*info;
	char 	*tmp;
	char	*test;
	char	*tmp2;

	test = ft_strdup("ft_ls: ");
	info = init_info();
	if (path[ft_strlen(path) - 1] != '/')
		info->path = ft_strjoin(path, "/");
	else
	{
		path[ft_strlen(path) - 1] = '\0';
		info->path = ft_strdup(path);
	}
	tmp2 = ft_strjoin(test, ft_strrchr(path, '/') + 1);
	tmp = ft_strjoin(tmp2, ": Permissions denied");
	info->name = ft_strdup(tmp);
	free(tmp);
	free(test);
	free(tmp2);
	info->is_dir = -1;
	push_back(cur, info);
}