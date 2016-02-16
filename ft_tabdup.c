/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:50:04 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 19:02:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			**ft_tabdup(char **ptr)
{
	int			i;
	char		**res;

	i = 0;
	while (ptr[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (ptr[i])
	{
		res[i] = ft_strdup(ptr[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
