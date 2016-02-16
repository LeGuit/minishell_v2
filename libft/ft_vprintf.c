/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:12:43 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 17:17:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		display_noc(t_mod *m, char cursor)
{
	int			i;

	i = 1;
	if (!GET(m->flag, F_MINUS))
	{
		while (i < m->length)
		{
			if (GET(m->flag, F_ZERO))
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}
	ft_putchar(cursor);
	if (GET(m->flag, F_MINUS))
	{
		while (i < m->length)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}

static int		output(t_mod *m, va_list ap, const char format)
{
	int			i;

	i = 0;
	if (m->convers)
		i += print_arg(m, ap);
	else
	{
		SET(m->flag, F_NCONV);
		i += (display_noc(m, format));
	}
	return (i);
}

int				ft_vprintf(const char *format, va_list ap)
{
	t_mod		m;
	size_t		i;
	int			ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (0);
			ft_bzero(&m, sizeof(t_mod));
			i += get_mod(&format[i + 1], &m, ap) + 1;
			ret += output(&m, ap, format[i]);
			if (GET(m.flag, F_NCONV))
				i++;
			continue;
		}
		ft_putchar(format[i]);
		ret++;
		i++;
	}
	return (ret);
}
