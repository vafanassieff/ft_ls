/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:13 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 00:00:10 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_elem(t_list *l, UINT *flag)
{
   t_elem *pelem = l->first;
   while(pelem)
   {
		if (pelem->info->name[0] != '.')
   	 		ft_putendl(pelem->info->name);
		else if (*flag & BYTE_A || *flag & BYTE_NOSORT)
			ft_putendl(pelem->info->name);
    	 pelem = pelem->next;
   }
}

void	show_file(t_list *arg_list, int nb)
{
	t_elem 	*tmp;
	t_elem	*remove;
	int 	i;

	tmp = arg_list->first;
	i = 0;
	while (tmp)
	{
		if(tmp->info->is_dir == 0)
		{
			ft_putendl(tmp->info->name);
			remove = tmp;
			tmp = tmp->next;
			remove_elem(remove, arg_list);
			i++;
		}
		else
			tmp = tmp->next;
	}
	if (i != nb && nb != 1 && i != 0)
		ft_putchar('\n');
}