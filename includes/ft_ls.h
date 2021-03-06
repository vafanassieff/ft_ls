/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:51:35 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/26 17:48:49 by vafanass         ###   ########.fr       */
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
# include <termios.h>
# include <sys/ioctl.h>

# define UINT 			unsigned int
# define BOOL 			int
# define TRUE 			1
# define FALSE 			0

# define BYTE_L 		((UINT)1 << 0)
# define BYTE_R 		((UINT)1 << 1)
# define BYTE_A 		((UINT)1 << 2)
# define BYTE_RS 		((UINT)1 << 3)
# define BYTE_T			((UINT)1 << 4)
# define BYTE_NOSORT	((UINT)1 << 5)
# define BYTE_1			((UINT)1 << 6)
# define BYTE_I			((UINT)1 << 7)
# define BYTE_BT		((UINT)1 << 8)
# define BYTE_D			((UINT)1 << 9)
# define BYTE_S			((UINT)1 << 10)

# define OPT_LIST		"Rlartf1TdiS"

typedef	struct		s_padding
{
	int				link;
	int				user;
	int				group;
	int				size;
	int				inode;
	int				major;
	int				minor;
	int				name;
	int				col;
}					t_padding;

typedef struct		s_info
{
	int				is_dir;
	char			*path;
	char			*name;
	char			type;
	char			*mode;
	char			*owner;
	char			*group;
	int				size;
	int				inode;
	char			*m_date;
	long int		m_time;
	unsigned int	nb_link;
	int				block_size;
	int				nb_block;
	int				major;
	int				minor;
}					t_info;

typedef struct		s_elem
{
	t_info			*info;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_list
{
	t_elem			*first;
	t_elem			*last;
}					t_list;

void				get_arg(int argc, char **argv, UINT *flag, t_list *list);
void				fill_arg(UINT *flag, t_list *l, int nb);
void				verif_arg(t_list *l, UINT *flag);
void				add_flag(UINT *flag, char *arg);
void				error_opt(char opt);
void				get_perror(char *str, int close);
void				error_fts_open();
void				permission_denied(char *path, t_list *cur);
void				push_back(t_list *l, t_info *info);
void				push_front(t_list *l, t_info *info);
void				free_list(t_list *l);
int					count_list(t_elem *first, int *len);
void				remove_elem(t_elem *elem, t_list *list);
void				swap_elem_content(t_elem **a, t_elem **b);
t_info				*init_info();
void				init(UINT *flag, t_list *l);
void				init_padding(t_padding *p);
void				sort_list(t_list *list, UINT *flag);
void				sort_list_reverse_ascii(t_elem *first, int len);
void				sort_reverse_modified_time(t_elem *first, int len);
void				sort_modified_time(t_elem *first, int len);
void				sort_list_ascii(t_elem *first, int len);
void				sort_list_dir(t_elem *first);
void				sort_reverse_size(t_elem *first, int len);
void				show_elem(t_list *l, UINT *flag);
void				show_file(t_list *arg_list, int nb, UINT *flag, int i);
void				recursive(UINT *flag, t_list *l, t_elem *last);
void				print_long(t_info *info, UINT *flag, t_padding *p);
void				print_format(t_info *info, UINT *flag, t_padding *p);
t_info				*get_data(char *path, char *name, UINT *flag, int code);
void				read_folder(t_list *cur, char *path, UINT *flag);
int					get_dir(struct stat *s);
char				get_type(struct stat	*s);
char				*get_mode(struct stat *s);
char				*get_owner(struct stat *s);
char				*get_group(struct stat *s);
void				get_time(time_t mtime, char **date, UINT *flag);
void				free_elem(t_elem *tmp);
void				get_padding(t_padding *p, t_list *l, UINT *flag);
int					get_int_len(int x);

#endif
