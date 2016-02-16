/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:42:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 19:01:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static t_ll		get_arg_sign(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_HH))
		return ((t_ll)(signed char)va_arg(ap, int));
	if (GET(m->modif, MOD_H))
		return ((t_ll)(short)va_arg(ap, int));
	if (GET(m->modif, MOD_LL))
		return ((t_ll)va_arg(ap, long));
	if (GET(m->modif, MOD_L))
		return (va_arg(ap, t_ll));
	if (GET(m->modif, MOD_J))
		return ((t_ll)va_arg(ap, intmax_t));
	if (GET(m->modif, MOD_Z))
		return ((t_ll)va_arg(ap, size_t));
	else
		return ((t_ll)va_arg(ap, int));
}

static void		get_buf(t_mod *m, t_ll arg, char *buf)
{
	if (arg < 0)
	{
		ft_slltstr(arg, buf);
		ft_memmove(buf, buf + 1, ft_strlen(buf));
		SET(m->flag, F_NEG);
	}
	else
		ft_slltstr(arg, buf);
}

int				print_sign(t_mod *m, va_list ap)
{
	size_t		cnt;
	t_ll		arg;
	char		buf[128];

	arg = get_arg_sign(m, ap);
	if (arg < 0)
	{
		UNSET(m->flag, F_SPACE);
		m->length--;
	}
	if (GET(m->flag, F_PLUS))
		m->length--;
	get_buf(m, arg, buf);
	cnt = display_ui(m, buf);
	return (cnt);
}
