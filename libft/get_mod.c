/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:36:07 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/29 13:35:22 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		get_flag(const char *cursor, t_mod *m)
{
	int			i;

	i = 0;
	while (cursor[i] == '#' || cursor[i] == '0' || cursor[i] == '-'
			|| cursor[i] == '+' || cursor[i] == ' ')
	{
		if (cursor[i] == '#')
			SET(m->flag, F_HASH);
		if (cursor[i] == '0')
			SET(m->flag, F_ZERO);
		if (cursor[i] == '-')
			SET(m->flag, F_MINUS);
		if (cursor[i] == ' ')
			SET(m->flag, F_SPACE);
		if (cursor[i] == '+')
			SET(m->flag, F_PLUS);
		i++;
	}
	return (i);
}

static int		get_length(const char *cursor, t_mod *m, va_list ap)
{
	int			i;

	i = 0;
	if (!ft_isdigit(*cursor) && *cursor != '*')
		return (0);
	if ((m->length = ft_atoi(cursor)))
	{
		while (ft_isdigit(cursor[i]))
			i++;
	}
	else if (cursor[i] == '*')
	{
		m->length = va_arg(ap, int);
		if (m->length < 0)
		{
			m->length = -(m->length);
			SET(m->flag, F_MINUS);
		}
		i++;
	}
	return (i);
}

static int		get_prec(const char *cursor, t_mod *m, va_list ap)
{
	int			i;

	if (*cursor != '.')
		return (0);
	SET(m->flag, F_PREC);
	i = 1;
	(m->prec = ft_atoi(cursor + i));
	while (ft_isdigit(cursor[i]))
		i++;
	if (cursor[i] == '*')
	{
		m->prec = va_arg(ap, int);
		if ((int)m->prec < 0 && ft_strchr("diuUoO", cursor[i + 1]))
			m->prec = 0;
		i++;
	}
	return (i);
}

static int		get_modif(const char *cursor, t_mod *m)
{
	int			i;

	i = 0;
	while (cursor[i] == 'h' || cursor[i] == 'l' || cursor[i] == 'j'
			|| cursor[i] == 'z')
	{
		if (cursor[i] == 'h' && cursor[i + 1] == 'h')
			SET(m->modif, MOD_HH);
		if (cursor[i] == 'h' && cursor[i + 1] != 'h')
			SET(m->modif, MOD_H);
		if (cursor[i] == 'l' && cursor[i + 1] == 'l')
			SET(m->modif, MOD_LL);
		if (cursor[i] == 'l' && cursor[i + 1] != 'l')
			SET(m->modif, MOD_L);
		if (cursor[i] == 'j')
			SET(m->modif, MOD_J);
		if (cursor[i] == 'z')
			SET(m->modif, MOD_Z);
		i++;
	}
	return (i);
}

int				get_mod(const char *cursor, t_mod *m, va_list ap)
{
	size_t		cnt;

	cnt = 0;
	cnt += get_flag(cursor, m);
	cnt += get_length(cursor + cnt, m, ap);
	cnt += get_prec(cursor + cnt, m, ap);
	if (*(cursor + cnt) == '.')
	{
		m->prec = 0;
		UNSET(m->flag, F_PREC);
		while (*(cursor + cnt) == '.' || ft_isdigit(*(cursor + cnt)))
			cnt++;
	}
	cnt += get_modif(cursor + cnt, m);
	if (!(cnt += get_convers(*(cursor + cnt), m)))
		return (0);
	return (cnt);
}
