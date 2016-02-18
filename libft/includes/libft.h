/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:43:55 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 17:47:54 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define ABS(x)				((x > 0) ? (x) : -(x))
# define MIN(x, y)			((x) > (y) ? (y) : (x))
# define MAX(x, y)			((x) < (y) ? (y) : (x))
# define GET(i, mask)		(i & mask)
# define SET(i, mask)		(i |= mask)
# define UNSET(i, mask)		(i &= ~(mask))
# define TOGGLE(i, mask)	(i ^= mask)
# define PRINT(i, mask)		ft_putchar(GET(i, mask) ? '1' : '0')
# define VECT_INI(type)		(t_vect){NULL, 0, 0, sizeof((type))}
# define C_NODE(type,ptr)	((type *)(ptr))
# define C_RED				"\033[31m"
# define C_YEL				"\033[33m"
# define C_BLU				"\033[34m"
# define C_MAG				"\033[35m"
# define C_LCYA				"\033[96m"
# define C_RES				"\033[39m"
# define B_YEL				"\033[43m"
# define B_CYA				"\033[46m"
# define B_RES				"\033[49m"

/*
** Fonction Memory libc
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memrcpy(void *dst, const void *src, size_t n);
void				*ft_memrcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** Fonction Memory supp
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
/*
** Fonction String libc
*/
size_t				ft_strlen(const char *s);
size_t				ft_strlen_ch(char const *s, char c);
size_t				ft_wstrlen(wchar_t *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strrcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*
** Fonction String supp
*/
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strealloc(char *str, size_t size);
/*
** Fonction Test
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_size_nb(int nb);
/*
** Fonction Manip
*/
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
long int			ft_atoll(const char *str);
char				*ft_itoa(int n);
void				ft_ulltstr_base(unsigned long long n, char *base_strm,
									char *buf);
void				ft_slltstr(long long n, char *buf);
/*
** Fonction Print
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnstr(char *str, size_t n);
void				ft_putnstr_fd(char *str, size_t n, int fd);
/*
** Fonction list general
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_last(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstfind(t_list *blist, void *ref, int (*cmp)());
/*
** Fonction list torvalds
*/
typedef struct		s_dlst
{
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

void				dlst_init(t_dlst *dlst);
void				dlst_add(t_dlst *new, t_dlst *prev, t_dlst *next);
void				dlst_add_head(t_dlst *new, t_dlst *dlst);
void				dlst_add_tail(t_dlst *new, t_dlst *dlst);
void				dlst_del(t_dlst *prev, t_dlst *next);
void				dlst_del_entry(t_dlst *entry);
void				dlst_replace(t_dlst *old, t_dlst *new);
void				dlst_replace_init(t_dlst *old, t_dlst *new);
void				dlst_del_init(t_dlst *entry);
void				dlst_move_head(t_dlst *entry, t_dlst *head);
void				dlst_move_tail(t_dlst *entry, t_dlst *head);
void				dlst_rotate(t_dlst *head);
void				dlst_rrotate(t_dlst *head);
int					dlst_empty(t_dlst *head);
int					dlst_is_last(t_dlst *dslt, t_dlst *head);
int					dlst_is_singular(t_dlst *head);
int					dlst_size(t_dlst *head);
void				dlst_swap(t_dlst *head);
void				dlst_cut_position(t_dlst *nlst, t_dlst *head,
					t_dlst *entry);
void				dlst_merge(t_dlst *heada, t_dlst *headb,
					int (*cmp)(t_dlst *, t_dlst *));
t_dlst				*dlst_go_to(t_dlst *head, int nb);
void				dlst_merge_sort(t_dlst *head,
					int (*cmp)(t_dlst *, t_dlst *));
void				dlst_rev(t_dlst *head);
/*
** Fonction vector
*/
typedef struct		s_vect
{
	void			*data;
	size_t			size;
	size_t			capacity;
	size_t			element_size;
}					t_vect;

int					ft_vect_push_back(t_vect *vect, void *buf);
int					ft_vect_reserve(t_vect *vect, size_t reserve);
int					ft_vect_del(t_vect *vect, int (*del)(void *));
/*
** Fonction vector
*/
char				**ft_tabdup(char **ptr);
void				ft_tabdel(char ***tab);
size_t				ft_tabsize(char **tab);

#endif
