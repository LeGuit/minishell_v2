/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 17:05:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				null_case(char *arg)
{
	if (!arg)
	{
		ft_putstr("(null)");
		return (1);
	}
	return (0);
}

static size_t	display_str(t_mod *m, char *buf)
{
	size_t		cnt;
	int			i;

	cnt = 0;
	if (!GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	i = 0;
	if (GET(m->flag, F_PREC) && m->prec < ft_strlen(buf))
	{
		while (i < (int)m->prec)
			ft_putchar(buf[i++]);
	}
	else
	{
		while (buf[i])
			ft_putchar(buf[i++]);
	}
	cnt += i;
	if (GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	return (cnt);
}

int				print_str(t_mod *m, va_list ap)
{
	size_t		cnt;
	char		*arg;

	arg = va_arg(ap, char *);
	if (!arg && GET(m->flag, F_PREC))
	{
		cnt = 0;
		while ((int)cnt < m->length)
		{
			if (GET(m->flag, F_ZERO))
				ft_putchar('0');
			else
				ft_putchar(' ');
			cnt++;
		}
		return (cnt);
	}
	else if (null_case(arg))
		return (6);
	cnt = display_str(m, arg);
	return (cnt);
}
