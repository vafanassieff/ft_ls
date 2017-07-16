/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:36:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/16 19:46:36 by vafanass         ###   ########.fr       */
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

BOOL	check_opt(char opt)
{
	if ((ft_strchr(OPT_LIST, opt)) == NULL)
		return (FALSE);
	else
		return (TRUE);
}

void 	add_arg(unsigned int *flag, char *arg)
{
	int len;
	int i;

	len = ft_strlen(arg);
	i = 1;
	
	while (i < len)
	{
		if (check_opt(arg[i]) == FALSE)
			error_opt(arg[i]);
		else if (arg[i] == 'l' && !(*flag & BYTE_L))
			*flag += BYTE_L;
		else if (arg[i] == 'R' && !(*flag & BYTE_R))
			*flag += BYTE_R;
		else if (arg[i] == 'a' && !(*flag & BYTE_A))
			*flag += BYTE_A;
		else if (arg[i] == 'r' && !(*flag & BYTE_RS))
			*flag += BYTE_RS;
		else if (arg[i] == 't' && !(*flag & BYTE_T))
			*flag += BYTE_T;
		i++;
	}
}

void	get_arg(int argc, char ** argv, unsigned int *flag)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			add_arg(flag, argv[i]);
		else
			break;
		i++;
	}
	while (i < argc)
	{
		i++;
	}
}
