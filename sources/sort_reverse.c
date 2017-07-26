/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:59:40 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 13:12:58 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_reverse_modified_time(t_elem *first, int len)
{
	t_elem	*tmp;

	tmp = first;
	while (len)
	{
		while (tmp->next)
		{
			if (tmp->info->m_time == tmp->next->info->m_time)
			{
				if (ft_strcmp(tmp->info->name, tmp->next->info->name) < 0)
					swap_elem_content(&tmp, &tmp->next);
			}
			else
			{
				if (tmp->info->m_time > tmp->next->info->m_time)
					swap_elem_content(&tmp, &tmp->next);
			}
			tmp = tmp->next;
		}
		tmp = first;
		len--;
	}
}

void	sort_list_reverse_ascii(t_elem *first, int len)
{
	t_elem 	*tmp;

	tmp = first;
	while (len)
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->info->name, tmp->next->info->name) < 0)
				swap_elem_content(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		tmp = first;
		len--;
	}
}