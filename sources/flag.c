/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:36:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/25 15:31:49 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

BOOL	check_opt(char opt)
{
	if ((ft_strchr(OPT_LIST, opt)) == NULL)
		return (FALSE);
	else
		return (TRUE);
}

void 	add_flag(UINT *flag, char *arg)
{
	int len;
	int i;

	len = ft_strlen(arg);
	i = 0;
	while (i++ < len)
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
		else if (arg[i] == 'f' && !(*flag & BYTE_NOSORT) && !(*flag & BYTE_A))
		{
			*flag += BYTE_NOSORT;
			*flag += BYTE_A;
		}
		else if (arg[i] == '1' && !(*flag & BYTE_1))
			*flag += BYTE_1;
		else if (arg[i] == 'T' && !(*flag & BYTE_BT))
			*flag += BYTE_BT;
		else if (arg[i] == 'd' && !(*flag & BYTE_D))
			*flag += BYTE_D;
	}
}