/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:47:48 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 01:20:06 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_whitespace(int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
}

void	print_long(t_info *info, UINT *flag, t_padding *p)
{
	if (*flag & BYTE_I)
	{
		ft_put_whitespace(p->inode - get_int_len(info->inode));
		ft_putnbr(info->inode);
		ft_put_whitespace(1);
	}
	ft_putchar(info->type);
	ft_putstr(info->mode);
	ft_put_whitespace(p->link - get_int_len(info->nb_link) + 2);
	ft_putnbr(info->nb_link);
	ft_putchar(' ');
	ft_putstr(info->owner);
	ft_put_whitespace(p->user - (int)ft_strlen(info->owner) + 2);
	//ft_put_whitespace(2);
	ft_putstr(info->group);
	ft_put_whitespace(p->group - (int)ft_strlen(info->group));
	ft_put_whitespace(p->size - get_int_len(info->size) + 2);
	ft_putnbr(info->size);
	ft_putstr(" ");
	ft_putstr(info->m_date);
	ft_putstr(" ");
	ft_putendl(info->name);
}

void	print_format(t_info *info, UINT *flag, t_padding *p)
{
	p->link = 0;
	if (*flag & BYTE_I)
		ft_putstr("toto");
	ft_putendl(info->name);
}