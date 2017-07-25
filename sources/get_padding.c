/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:36:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 16:39:33 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_padding(t_padding *p, t_list *l, UINT *flag)
{
	t_elem	*elem;

	elem = l->first;
	if (*flag & BYTE_I)
		printf("toto");
	init_padding(p);
}