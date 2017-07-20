/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:51:35 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/20 16:17:25 by vafanass         ###   ########.fr       */
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
# include <errno.h>

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

typedef struct 		s_info
{
	char			*path;
	char			*name;
	int				type;
	int				is_dir;
}					t_info;

typedef struct 		s_elem{
	t_info			*info;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_list
{
	t_elem			*first;
	t_elem			*last;
}					t_list;

void 				printbits(unsigned int v);
void				get_arg(int argc, char ** argv, unsigned int *flag, t_list *list);
void 				push_back(t_list *l, t_info *info);
void 				push_front(t_list *l, t_info *info);
void free_list(t_list *l);
void 				view_list(t_list *l);
t_info	*init_info();
void 				error_opt(char opt);
void	get_perror(char *str, int close);
int		count_list(t_elem *first);
void	sort_list_ascii(t_elem *first);
void	swap_elem_content(t_elem **a, t_elem **b);
t_info	*init_info();
void	init(unsigned int *flag, t_list *l);
void	remove_elem(t_elem *elem, t_list *list);
void	verif_arg(t_list *l);
void 	sort_list(t_elem *first, unsigned int flag);
#endif
