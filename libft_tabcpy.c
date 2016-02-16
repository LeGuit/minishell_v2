/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:11:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:16:34 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				ft_tabcpy(char **dsttab, char **srctab)
{
	int				i;

	i = 0;
	while (srctab[i])
	{
			dsttab[i] = ft_strdup(srctab[i]);
			i++;
	}
}