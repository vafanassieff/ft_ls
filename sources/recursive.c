/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:51:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 16:16:36 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive(UINT *flag, t_list *l)
{
	t_elem	*elem;
	t_list	cur;
	char 	*tmp;

	elem = l->first;
	while (elem)
	{
		cur.first = NULL;
		cur.last = NULL;
		if (elem->info->is_dir == 1 && !(*flag & BYTE_A) && ft_strncmp(elem->info->name, ".", 1) == 0)
			elem = elem->next;
		else
		{
			if (elem->info->is_dir == 1 && ft_strcmp(elem->info->name, "..") != 0 && ft_strcmp(elem->info->name, ".") != 0)
 			{
				tmp = ft_strjoin(elem->info->path, elem->info->name);
				read_folder(&cur, tmp, flag);
				free(tmp);
				sort_list(cur.first, flag);
				tmp = cur.first->info->path;
				tmp[ft_strlen(tmp)- 1 ] = '\0';
				ft_putstr(tmp);
				ft_putendl(":");
				show_elem(&cur, flag);
				ft_putchar('\n');
				recursive(flag, &cur);
				free_list(&cur);
				elem = elem->next;
			}
			else
				elem = elem->next;
		}
	}
}