/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:51:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 17:34:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	recursive_next(UINT *flag, t_list *cur, t_elem *last, t_elem *elem)
{
	char	*tmp;

	tmp = ft_strjoin(elem->info->path, elem->info->name);
	read_folder(cur, tmp, flag);
	free(tmp);
	sort_list(cur, flag);
	tmp = cur->first->info->path;
	tmp[ft_strlen(tmp) - 1] = '\0';
	ft_putstr(tmp);
	ft_putendl(":");
	show_elem(cur, flag);
	if (elem != last)
		ft_putchar('\n');
	recursive(flag, cur, last);
	free_list(cur);
}

void		recursive(UINT *flag, t_list *l, t_elem *last)
{
	t_elem	*elem;
	t_list	cur;

	elem = l->first;
	while (elem)
	{
		cur.first = NULL;
		cur.last = NULL;
		if (elem->info->is_dir == 1 && !(*flag & BYTE_A)
			&& ft_strncmp(elem->info->name, ".", 1) == 0)
			elem = elem->next;
		else
		{
			if (elem->info->is_dir == 1 && ft_strcmp(elem->info->name, "..")
				!= 0 && ft_strcmp(elem->info->name, ".") != 0)
			{
				recursive_next(flag, &cur, last, elem);
				elem = elem->next;
			}
			else
				elem = elem->next;
		}
	}
}
