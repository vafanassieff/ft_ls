/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/18 18:40:28 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void PushBack(t_list *l, char *path)
{
   t_elem *nouv = malloc(sizeof(t_elem));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->info = malloc(sizeof(t_info));
   nouv->info->path = NULL;
   nouv->info->path	= ft_strdup(path);
   nouv->prev = l->last;
   nouv->next = NULL;
   if(l->last) l->last->next = nouv;
   else l->first = nouv;
   l->last = nouv;        
}

void PushFront(t_list *l, char *path)
{
   t_elem *nouv = malloc(sizeof(t_elem));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->info = malloc(sizeof(t_info));
   nouv->info->path = NULL;
   nouv->info->path	= ft_strdup(path);
   nouv->next = l->first;
   nouv->prev = NULL;      
   if(l->first) l->first->prev = nouv;
   else l->last = nouv;
   l->first = nouv;
}

void View(t_list l)
{
   t_elem *pelem = l.first;
   while(pelem)
   {
     printf("%s\n",pelem->info->path);
     pelem = pelem->next;
   }
}

void	init(unsigned int *flag, t_list *l)
{
   	l->first = NULL;
   	l->last = NULL;
	*flag = 0;
}

int 	main(int argc, char **argv)
{
	unsigned int 	flag;
	t_list			MaListe;

	init(&flag, &MaListe);
	get_arg(argc, argv, &flag);
	printbits(flag);
	int i = 0;
	while (++i < argc)
		PushBack(&MaListe, argv[i]);
	View(MaListe);
	return(0);
}