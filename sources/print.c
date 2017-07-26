/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:47:48 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 16:20:17 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_put_whitespace(int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
}

static void	print_long_next(t_info *info, t_padding *p)
{
	ft_putchar(info->type);
	ft_putstr(info->mode);
	ft_put_whitespace(p->link - get_int_len(info->nb_link) + 2);
	ft_putnbr(info->nb_link);
	ft_putchar(' ');
	ft_putstr(info->owner);
	ft_put_whitespace(p->user - (int)ft_strlen(info->owner) + 2);
	ft_putstr(info->group);
	ft_put_whitespace(p->group - (int)ft_strlen(info->group));
	if (info->type == 'c' || info->type == 'b')
	{
		ft_put_whitespace(p->major - get_int_len(info->major) + 1);
		ft_putnbr(info->major);
		ft_putchar(',');
		ft_put_whitespace(p->minor - get_int_len(info->minor) + 1);
		ft_putnbr(info->minor);
	}
	else
	{
		ft_put_whitespace(p->size - get_int_len(info->size)
			+ 2 + p->major + p->minor);
		ft_putnbr(info->size);
	}
}

void		print_long(t_info *info, UINT *flag, t_padding *p)
{
	if (*flag & BYTE_I)
	{
		ft_put_whitespace(p->inode - get_int_len(info->inode));
		ft_putnbr(info->inode);
		ft_put_whitespace(1);
	}
	print_long_next(info, p);
	ft_putstr(" ");
	ft_putstr(info->m_date);
	ft_putstr(" ");
	ft_putendl(info->name);
}

void		print_format(t_info *info, UINT *flag, t_padding *p)
{
	if (*flag & BYTE_I)
	{
		ft_put_whitespace(p->inode - get_int_len(info->inode));
		ft_putnbr(info->inode);
		ft_put_whitespace(1);
	}
	ft_putendl(info->name);
}
