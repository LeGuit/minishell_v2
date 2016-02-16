/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:11:30 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/01 10:34:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	display_zero(t_mod *m, char *buf)
{
	int			i;

	i = 0;
	if (GET(m->flag, F_HO) && *buf != '0')
		m->prec = ft_strlen(buf) + 1;
	while (i < (int)(m->prec - ft_strlen(buf)))
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

size_t			display_space(t_mod *m, char *buf)
{
	size_t		i;
	size_t		nospace;

	i = 0;
	if (ft_strchr("sS", m->convers) && GET(m->flag, F_PREC))
		nospace = (m->prec < ft_strlen(buf) ? m->prec : ft_strlen(buf));
	else
		nospace = ((m->prec) ? MAX(m->prec, ft_strlen(buf)) : ft_strlen(buf));
	if (GET(m->flag, F_ZERO) && GET(m->flag, F_PLUS) && m->prefix[0] == '-')
		nospace--;
	if (ft_strchr("c", m->convers) && !*buf)
		nospace = 1;
	if (GET(m->flag, F_HO))
		nospace = ft_strlen(buf) + 1;
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

size_t			display_ui(t_mod *m, char *buf)
{
	size_t		cnt;

	cnt = 0;
	cnt += display_prefix(m, buf);
	if (GET(m->flag, F_ZERO))
		ft_putstr(m->prefix);
	if (!GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	if (!GET(m->flag, F_ZERO))
		ft_putstr(m->prefix);
	cnt += display_zero(m, buf);
	ft_putstr(buf);
	cnt += ft_strlen(buf);
	if (GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	return (cnt);
}

int				print_modulo(t_mod *m, va_list ap)
{
	size_t		cnt;

	(void)ap;
	cnt = 1;
	if (GET(m->flag, F_MINUS))
		ft_putchar('%');
	if (GET(m->flag, F_PREC) || m->length)
	{
		while ((int)cnt < m->length)
		{
			if (GET(m->flag, F_ZERO))
				ft_putchar('0');
			else
				ft_putchar(' ');
			cnt++;
		}
	}
	if (!GET(m->flag, F_MINUS))
		ft_putchar('%');
	return (cnt);
}
