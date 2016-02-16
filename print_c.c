/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 15:24:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>

static int		get_arg_c(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_L))
		return ((int)va_arg(ap, wint_t));
	else
		return (va_arg(ap, int));
}

size_t			display_c(t_mod *m, int arg)
{
	size_t		cnt;
	char		buf[5];

	cnt = 0;
	ft_widetoa(buf, 5, arg);
	if (!GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	if (!GET(m->modif, MOD_L) && arg > 127)
	{
		ft_putchar(arg);
		cnt += 1;
	}
	else
	{
		ft_putstr(buf);
		cnt += (ft_strlen(buf) ? ft_strlen(buf) : 1);
	}
	if (!*buf)
		ft_putchar('\0');
	if (GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	return (cnt);
}

int				print_c(t_mod *m, va_list ap)
{
	size_t		cnt;
	int			arg;

	arg = get_arg_c(m, ap);
	cnt = display_c(m, arg);
	return (cnt);
}
