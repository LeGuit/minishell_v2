/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:53:04 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/17 18:50:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_widetoa(char *buf, size_t buf_size, int wc)
{
	ft_bzero(buf, buf_size);
	if (wc < 0x80)
		buf[0] = (wc & 0x7F) | 0;
	else if (wc < 0x800)
	{
		buf[1] = (wc & 0x3F) | 0x80;
		buf[0] = ((wc >> 6) & 0x1F) | 0xC0;
	}
	else if (wc < 0x10000)
	{
		buf[2] = (wc & 0x3F) | 0x80;
		buf[1] = (wc >> 6 & 0x3F) | 0x80;
		buf[0] = (wc >> 12 & 0xF) | 0xE0;
	}
	else if (wc < 0x110000)
	{
		buf[3] = (wc & 0x3F) | 0x80;
		buf[2] = (wc >> 6 & 0x3F) | 0x80;
		buf[1] = (wc >> 12 & 0x3F) | 0x80;
		buf[0] = (wc >> 18 & 0x7) | 0xF0;
	}
}
