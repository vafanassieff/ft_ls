/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:47:48 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 19:39:08 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_info *info, UINT *flag)
{
			ft_putchar(info->type);
			ft_putstr(info->mode);
			ft_putstr(" ");
			ft_putnbr(info->nb_link);
			ft_putstr("    ");
			ft_putstr(info->owner);
			ft_putstr("    ");
			ft_putstr(info->group);
			ft_putstr("    ");
			ft_putnbr(info->size);
			ft_putstr("  ");
			ft_putstr(info->m_date);
			ft_putstr(" ");
			ft_putendl(info->name);
}

void	print_format(t_info *info, UINT *flag)
{
	ft_putendl(info->name);
}