/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:03:20 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/19 21:30:28 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	error_opt(char opt)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(opt);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-aRlrt] [file ...]");
	ft_putchar('\n');
	exit(1);
}

void	open_error(char *str)
{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": ");
		perror("");
}