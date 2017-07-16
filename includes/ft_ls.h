/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:51:35 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/16 19:54:45 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

# define UINT unsigned int
# define BOOL int
# define TRUE 1
# define FALSE 0

# define BYTE_L 		((UINT)1 << 0)
# define BYTE_R 		((UINT)1 << 1)
# define BYTE_A 		((UINT)1 << 2)
# define BYTE_RS 		((UINT)1 << 3)
# define BYTE_T			((UINT)1 << 4)
# define BYTE_NONE		((UINT)1 << 5)

# define OPT_LIST		"Rlart"

typedef struct 		s_infos{
	char			*path;
	int				type;
}					t_info;

typedef struct 		s_llist{
	t_info			*info;
	struct t_llist	*next;
	struct t_llist	*prev;
}					t_llist;

void 				printbits(unsigned int v);
void	get_arg(int argc, char ** argv, unsigned int *flag);

#endif
