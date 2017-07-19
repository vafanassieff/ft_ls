/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:42:07 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/19 21:03:38 by vafanass         ###   ########.fr       */
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

void free_list(t_list *l)
{
   t_elem *tmp;
   t_elem *pelem;

   pelem = l->first;
   while(pelem)
   {
     	tmp = pelem;
		if (tmp->info->path)
	 		free(tmp->info->path);
		if(tmp->info->name)
			free(tmp->info->name);
		free(tmp->info);
		free(tmp);
     	pelem = pelem->next;
   }
   l->first = NULL;
   l->last = NULL;
}

int		count_list(t_list *l)
{
	t_elem *p;
	int 	i;

	i = 0;
	p = l->first;
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