/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/16 19:47:52 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init(unsigned int *flag)
{
	*flag = 0;
}

int 	main(int argc, char **argv)
{
	unsigned int flag;

	init(&flag);
	get_arg(argc, argv, &flag);
	printbits(flag);
	//printf("\n dir_index = %d\n", e->dir_index);
	return(0);
}