/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tabsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:08:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:10:01 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t				ft_tabsize(char **tab)
{
	size_t			size;

	if (!tab)
		return (0);
	size = 0;
	while (tab[size])
		size++;
	return (size);
}