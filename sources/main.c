/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/23 18:49:18 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//TO DO LIST

// REMOVE LASY \N
// FASTER SORT

int 	main(int argc, char **argv)
{
	int			nb;
	UINT 		flag;
	t_list		arg_list;
	
	init(&flag, &arg_list);
	get_arg(argc, argv, &flag, &arg_list);
	count_list(arg_list.first, &nb);
	sort_list(arg_list.first, &flag);
	verif_arg(&arg_list);
	show_file(&arg_list, nb);
	fill_arg(&flag, &arg_list, nb);
	free_list(&arg_list);
	return(0);
}