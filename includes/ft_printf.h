/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:20:08 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/01 10:13:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define F_HASH				(1u << 0)
# define F_ZERO				(1u << 1)
# define F_MINUS			(1u << 2)
# define F_SPACE			(1u << 3)
# define F_PLUS				(1u << 4)
# define F_PREC				(1u << 5)
# define F_NEG				(1u << 6)
# define F_HO				(1u << 7)
# define F_PTR				(1u << 8)
# define F_NCONV			(1u << 9)
# define F_ALL				((1u << 10) - 1)

# define MOD_HH				(1u << 0)
# define MOD_H				(1u << 1)
# define MOD_LL				(1u << 2)
# define MOD_L				(1u << 3)
# define MOD_J				(1u << 4)
# define MOD_Z				(1u << 5)
# define MOD_ALL			(MOD_HH | MOD_H | MOD_LL | MOD_L | MOD_J | MOD_Z)

typedef struct				s_mod
{
	int						flag;
	int						length;
	size_t					prec;
	int						modif;
	char					convers;
	char					prefix[3];
}							t_mod;

typedef int					(*t_fct)(t_mod *mod, va_list va);
typedef unsigned long long	t_ull;
typedef long long			t_ll;

int							ft_printf(const char *format, ...);
int							is_there_modif(char modif);
int							get_mod(const char *cursor, t_mod *mod, va_list ap);
int							ft_vprintf(const char *format, va_list ap);
int							get_convers(char cursor, t_mod *m);
int							conv_s(t_mod *m, va_list ap);
int							print_arg(t_mod *m, va_list ap);
void						process_flags(t_mod *m);
void						process_modifier(t_mod *m);
void						process_ptr(t_mod *m);
size_t						ft_space(t_mod *m, size_t t);
void						ft_widetoa(char *buf, size_t buf_size, int wc);

int							print_modulo(t_mod *m, va_list ap);
int							print_u(t_mod *m, va_list ap);
int							print_sign(t_mod *m, va_list ap);
int							print_str(t_mod *m, va_list ap);
int							print_c(t_mod *m, va_list ap);
int							print_wstr(t_mod *m, va_list ap);
size_t						display_space(t_mod *m, char *buf);
int							null_case(char *arg);
size_t						display_ui(t_mod *m, char *buf);
size_t						display_prefix(t_mod *m, char *buf);

#endif
