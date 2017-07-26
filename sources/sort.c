/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:14:52 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 13:15:02 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list_dir(t_elem *first)
{
	t_elem *tmp;
	int		len;
	
	count_list(first, &len);
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

void	sort_list_ascii(t_elem *first, int len)
{
	t_elem *tmp;

	tmp = first;
	while (len)
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->info->name, tmp->next->info->name) > 0)
				swap_elem_content(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		tmp = first;
		len--;
	}
}

void	sort_modified_time(t_elem *first, int len)
{
	t_elem *tmp;

	tmp = first;
	while (len)
	{
		while (tmp->next)
		{
			if (tmp->info->m_time == tmp->next->info->m_time)
			{
				if (ft_strcmp(tmp->info->name, tmp->next->info->name) > 0)
					swap_elem_content(&tmp, &tmp->next);
			}
			else
			{
				if (tmp->info->m_time < tmp->next->info->m_time)
					swap_elem_content(&tmp, &tmp->next);
			}
			tmp = tmp->next;
		}
		tmp = first;
		len--;
	}
}

void 	sort_list(t_elem *first, UINT *flag)
{
	int		len;

	count_list(first, &len);
	if ((*flag & BYTE_T) && (*flag & BYTE_RS))
		sort_reverse_modified_time(first, len);
	else if (*flag & BYTE_T)
		sort_modified_time(first, len);
	else if (*flag & BYTE_RS && !(*flag & BYTE_NOSORT))
		sort_list_reverse_ascii(first, len);
	else if (!(*flag & BYTE_NOSORT))
		sort_list_ascii(first, len);
	else
		return;
}