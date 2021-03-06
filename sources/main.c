/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:49:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 17:16:39 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			nb;
	UINT		flag;
	t_list		arg_list;

	init(&flag, &arg_list);
	get_arg(argc, argv, &flag, &arg_list);
	count_list(arg_list.first, &nb);
	sort_list(&arg_list, &flag);
	verif_arg(&arg_list, &flag);
	show_file(&arg_list, nb, &flag, 0);
	fill_arg(&flag, &arg_list, nb);
	free_list(&arg_list);
	return (0);
}
