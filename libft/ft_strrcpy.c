/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:54:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/14 11:56:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrcpy(char *dst, const char *src)
{
	int	i;

	i = ft_strlen(src);
	dst[i] = '\0';
	while (--i)
		dst[i] = src[i];
	return (dst);
}
