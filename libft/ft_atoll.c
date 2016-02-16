/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:03:40 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 10:03:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long int		ft_atoll(const char *str)
{
	int			sign;
	long int	res;

	while (*str == '\n' || *str == '\v' || *str == '\r' || *str == ' ' ||
			*str == '\f' || *str == '\t')
		str++;
	sign = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str) == 1)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = (sign == 1 ? (-res) : res);
	return (res);
}
