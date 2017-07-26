/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:42:07 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 16:15:50 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_elem(t_elem *tmp)
{
	if (tmp->info->path)
		free(tmp->info->path);
	if (tmp->info->name)
		free(tmp->info->name);
	if (tmp->info->mode)
		free(tmp->info->mode);
	if (tmp->info->m_date)
		free(tmp->info->m_date);
	free(tmp->info);
	free(tmp);
}

void	free_list(t_list *l)
{
	t_elem *tmp;
	t_elem *pelem;

	pelem = l->first;
	while (pelem)
	{
		tmp = pelem;
		pelem = pelem->next;
		free_elem(tmp);
	}
	l->first = NULL;
	l->last = NULL;
}

int		count_list(t_elem *first, int *len)
{
	t_elem	*p;
	int		i;

	i = 0;
	p = first;
	while (p)
	{
		i++;
		p = p->next;
	}
	*len = i;
	return (i);
}

void	swap_elem_content(t_elem **a, t_elem **b)
{
	t_info *temp;

	temp = (*a)->info;
	(*a)->info = (*b)->info;
	(*b)->info = temp;
}

void	remove_elem(t_elem *elem, t_list *list)
{
	if (elem->next == NULL && elem->prev == NULL)
	{
		free_elem(elem);
		list->first = NULL;
		list->last = NULL;
		return ;
	}
	if (elem->prev == NULL)
	{
		elem->next->prev = NULL;
		list->first = elem->next;
	}
	else if (elem->next != NULL)
		elem->next->prev = elem->prev;
	if (elem->next == NULL)
	{
		elem->prev->next = NULL;
		list->last = elem->prev;
	}
	else if (elem->prev != NULL)
		elem->prev->next = elem->next;
	free_elem(elem);
}
