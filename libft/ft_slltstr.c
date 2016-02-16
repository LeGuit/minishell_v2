/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slltstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:24:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/16 12:50:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		len_str(long long n)
{
	int			cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n / 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void			ft_slltstr(long long n, char *buf)
{
	int			size;

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = 0;
		return ;
	}
	size = len_str(n);
	buf[size + 1] = 0;
	if (n < 0)
		buf[0] = '-';
	while (n)
	{
		buf[size] = ABS(n % 10) + '0';
		size--;
		n /= 10;
	}
}
