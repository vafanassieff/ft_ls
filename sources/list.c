/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:42:07 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 13:56:23 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void push_back(t_list *l, t_info *info)
{
	t_elem *new;
	
	new = malloc(sizeof(t_elem));
    if(!new) 
      	exit(EXIT_FAILURE);
    new->info = info;
    new->prev = l->last;
    new->next = NULL;
    if(l->last)
		l->last->next = new;
    else
		l->first = new;
	l->last = new;        
}

void push_front(t_list *l, t_info *info)
{
   	t_elem *new;
	
	new = malloc(sizeof(t_elem));
   	if(!new)
		exit(EXIT_FAILURE);
	new->info = info;
	new->next = l->first;
   	new->prev = NULL;      
   	if(l->first)
		l->first->prev = new;
	else
		l->last = new;
   l->first = new;
}

void free_elem(t_elem *tmp)
{
	if (tmp->info->path)
	 	free(tmp->info->path);
	if(tmp->info->name)
		free(tmp->info->name);
	free(tmp->info);
	free(tmp);
}

void free_list(t_list *l)
{
	t_elem *tmp;
	t_elem *pelem;

	pelem = l->first;
  	while(pelem)
  	{
  	   	tmp = pelem;
		free_elem(tmp);
    	pelem = pelem->next;
  	}
	l->first = NULL;
   	l->last = NULL;
}

int		count_list(t_elem *first)
{
	t_elem *p;
	int 	i;

	i = 0;
	p = first;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void view_list(t_list *l)
{
   t_elem *pelem = l->first;
   while(pelem)
   {
     printf("Path = %s | Name = %s\n", pelem->info->path, pelem->info->name);
     pelem = pelem->next;
   }
}

void	swap_elem_content(t_elem **a, t_elem **b)
{
	t_info *temp;

	temp = (*a)->info;
	(*a)->info = (*b)->info;
	(*b)->info = temp;
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

void	remove_elem(t_elem *elem, t_list *list)
{
	if (elem->next == NULL && elem->prev == NULL)
	{
		free_elem(elem);
		list->first = NULL;
		list->last = NULL;
		return;
	}
	if(elem->prev == NULL)
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