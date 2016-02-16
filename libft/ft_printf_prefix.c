/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 10:11:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/01 10:26:56 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			prefix_x(t_mod *m, char *buf)
{
	if (GET(m->flag, F_PTR) || (ft_strchr("xX", m->convers) && *buf != '0'))
	{
		if (GET(m->flag, F_HASH) && m->convers == 'x')
			ft_strcpy(m->prefix, "0x");
		if (GET(m->flag, F_HASH) && m->convers == 'X')
			ft_strcpy(m->prefix, "0X");
		if (GET(m->flag, F_HASH) && ft_strchr("xX", m->convers) && m->length)
			m->length = ((m->length < 2) ? 2 : m->length - 2);
		if (GET(m->flag, F_PTR) && GET(m->flag, F_PREC) && m->prec == 0)
			m->length = 0;
	}
}

size_t				display_prefix(t_mod *m, char *buf)
{
	prefix_x(m, buf);
	if (GET(m->flag, F_PLUS) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, "+");
	if (GET(m->flag, F_NEG) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, "-");
	if (GET(m->flag, F_SPACE) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, " ");
	if (GET(m->flag, F_HASH) && m->convers == 'o' && m->prec <= ft_strlen(buf))
		SET(m->flag, F_HO);
	if (GET(m->flag, F_SPACE))
		m->length--;
	if (GET(m->flag, F_PREC) && m->prec == 0 && *buf == '0')
		*buf = '\0';
	return (ft_strlen(m->prefix));
}
