/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:34:33 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/21 16:46:29 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void printbits(UINT v)
{
  	int i;

  	i = 31;
 	 while (i >= 0)
 	 {
  		ft_putchar('0' + ((v >> i) & 1));
		i--;
  	}
	ft_putchar('\n');
}