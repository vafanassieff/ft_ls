/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:36:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/21 16:47:18 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

BOOL	check_opt(char opt)
{
	if ((ft_strchr(OPT_LIST, opt)) == NULL)
		return (FALSE);
	else
		return (TRUE);
}

void 	add_arg(UINT *flag, char *arg)
{
	int len;
	int i;

	len = ft_strlen(arg);
	i = 0;
	
	while (i++ < len)
	{
		if (check_opt(arg[i]) == FALSE)
			error_opt(arg[i]);
		else if (arg[i] == 'l' && !(*flag & BYTE_L))
			*flag += BYTE_L;
		else if (arg[i] == 'R' && !(*flag & BYTE_R))
			*flag += BYTE_R;
		else if (arg[i] == 'a' && !(*flag & BYTE_A))
			*flag += BYTE_A;
		else if (arg[i] == 'r' && !(*flag & BYTE_RS))
			*flag += BYTE_RS;
		else if (arg[i] == 't' && !(*flag & BYTE_T))
			*flag += BYTE_T;
	}
}

void	get_arg(int argc, char ** argv, UINT *flag, t_list *list)
{
	int 	i;
	int		test;
	t_info	*info;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1])
			add_arg(flag, argv[i]);
		else
			break;
	}
	while (i < argc)
	{
		info = init_info();
		info->path = ft_strdup(argv[i]);
		info->name = ft_strdup(argv[i]);
		push_back(list, info);
		i++;
		test = TRUE;
	}
	if (test != TRUE)
	{
		info = init_info();
		info->path = ft_strdup("./");
		info->name = ft_strdup("./");
		push_back(list, info);
	}
}

void	verif_arg(t_list *l)
{
	t_elem	*tmp;
	t_elem	*remove;
	struct 	stat s;

	tmp = l->first;
	while (tmp)
	{
		if (ft_strcmp(tmp->info->path, "") == 0)
			error_fts_open();
		else if (stat(tmp->info->path,&s) < 0)
		{
			get_perror(tmp->info->path, 0);
			remove = tmp;
			tmp = tmp->next;
			remove_elem(remove, l);
		}
		else
		{
			if (S_ISDIR(s.st_mode))
				tmp->info->is_dir = 1;
			else
				tmp->info->is_dir = 0;
			tmp = tmp->next;
		}
	}
}