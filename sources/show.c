/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:45:13 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 19:21:58 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		show_total_blocksize(t_list *l, UINT *flag)
{
	t_elem	*ptr;
	int 	total;

	total = 0;
	ptr = l->first;
	while(ptr)
	{
		if (!(*flag & BYTE_A) && ptr->info->name[0] == '.')
			ptr = ptr->next;
		else
		{
			total += ptr->info->nb_block;
			ptr = ptr->next;
		}
	}
	ft_putstr("total ");
   	ft_putnbr(total);
   	ft_putchar('\n');
}

void		show_elem(t_list *l, UINT *flag)
{
   t_elem *pelem = l->first;
	if (*flag & BYTE_L)
		show_total_blocksize(l, flag);
   while(pelem)
   {
		if (pelem->info->name[0] != '.')
		{
			if (*flag & BYTE_L)
				print_format(pelem->info, flag);
			else
				ft_putendl(pelem->info->name);
		}
		else if (*flag & BYTE_A)
		{
			if (*flag & BYTE_L)
				print_format(pelem->info, flag);
			else
				ft_putendl(pelem->info->name);
		}
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