/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:14:52 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 18:14:29 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list_dir(t_elem *first)
{
	t_elem *tmp;
	int		len;
	
	len = count_list(first);
	tmp = first;
	while (len)
	{
		while (tmp->next)
		{
			if (tmp->info->is_dir > tmp->next->info->is_dir)
				swap_elem_content(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		tmp = first;
		len--;
	}
}

void	sort_list_ascii(t_elem *first)
{
	t_elem *tmp;
	int		len;
	
	len = count_list(first);
	tmp = first;
	while (len)
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->info->path, tmp->next->info->path) > 0)
				swap_elem_content(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		tmp = first;
		len--;
	}
}

void 	sort_list(t_elem *first, unsigned int flag)
{
	if (flag & BYTE_T)
		printf("sort t");
	else
		sort_list_ascii(first);
}