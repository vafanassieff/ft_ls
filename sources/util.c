/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:34:33 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 17:03:54 by vafanass         ###   ########.fr       */
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

int get_int_len (int x)
{
    if(x >= 1000000000)
		return 10;
    if(x >= 100000000)
		return 9;
    if(x >= 10000000)
		return 8;
    if(x >= 1000000)
		return 7;
    if(x >= 100000)
		return 6;
    if(x >= 10000)
		return 5;
    if(x >= 1000)
		return 4;
    if(x >= 100)
		return 3;
    if(x >= 10)
		return 2;
    return 1;
}