/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 16:16:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 16:16:13 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	push_back(t_list *l, t_info *info)
{
	t_elem		*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		exit(EXIT_FAILURE);
	new->info = info;
	new->prev = l->last;
	new->next = NULL;
	if (l->last)
		l->last->next = new;
	else
		l->first = new;
	l->last = new;
}

void	push_front(t_list *l, t_info *info)
{
	t_elem		*new;
	t_elem		*ptr;

	ptr = l->first;
	new = malloc(sizeof(t_elem));
	if (!new)
		exit(EXIT_FAILURE);
	new->info = info;
	new->next = l->first;
	new->prev = NULL;
	if (l->first)
		l->first->prev = new;
	else
		l->last = new;
	l->first = new;
}
