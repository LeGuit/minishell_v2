/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 11:53:06 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	display_space_w(t_mod *m, size_t size)
{
	size_t		i;
	size_t		nospace;

	i = 0;
	nospace = size;
	while ((int)i < (m->length - (int)nospace))
	{
		if (GET(m->flag, F_ZERO))
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

static size_t	size_wc(int wc)
{
	char		tmp[5];

	ft_widetoa(tmp, 5, wc);
	return (ft_strlen(tmp));
}

static size_t	sizew_to_print(t_mod *m, wchar_t *buf)
{
	int			i;
	size_t		sizew;
	char		tmp[5];
	int			flag;
	int			tmprec;

	i = 0;
	sizew = 0;
	flag = 0;
	tmprec = (int)m->prec;
	if (GET(m->flag, F_PREC))
		flag = 1;
	while (buf[i] && (flag ? (int)sizew < tmprec : 1))
	{
		if ((tmprec - sizew) < size_wc(buf[i]) && GET(m->flag, F_PREC))
			break ;
		ft_widetoa(tmp, 5, (int)(buf[i]));
		sizew += ft_strlen(tmp);
		i++;
	}
	return (sizew);
}

size_t			display_wstr(t_mod *m, wchar_t *buf)
{
	size_t		cnt;
	char		tmp[5];
	size_t		sizew;
	size_t		prec;

	cnt = sizew_to_print(m, buf);
	prec = MIN(m->prec, cnt);
	if (!GET(m->flag, F_MINUS))
		cnt += display_space_w(m, cnt);
	sizew = 0;
	while (GET(m->flag, F_PREC) ? sizew <= prec : *buf)
	{
		if ((prec - sizew) < size_wc(*buf) && GET(m->flag, F_PREC))
			break ;
		ft_widetoa(tmp, 5, (int)(*buf));
		ft_putstr(tmp);
		sizew += size_wc(*buf);
		buf++;
	}
	if (GET(m->flag, F_MINUS))
		cnt += display_space_w(m, cnt);
	return (cnt);
}

int				print_wstr(t_mod *m, va_list ap)
{
	wchar_t		*arg;
	size_t		size;

	arg = va_arg(ap, wchar_t *);
	if (null_case((char *)arg))
		return (6);
	size = display_wstr(m, arg);
	return (size);
}
