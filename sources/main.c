/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/13 16:51:54 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(void)
{
	DIR *test;
	struct dirent *readfile;


	test = opendir(".");
	
	while ((readfile = readdir(test)) != NULL)
	{
		ft_putstr(readfile->d_name);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return(0);
}