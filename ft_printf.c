/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:53:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/14 18:54:19 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = ft_vprintf(format, ap);
	va_end(ap);
	return (res);
}
