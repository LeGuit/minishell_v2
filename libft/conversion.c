/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:39:49 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 15:32:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						get_convers(char cursor, t_mod *m)
{
	if (!ft_strchr("sSpdDioOuUxXcC%", cursor))
		return (0);
	m->convers = cursor;
	return (1);
}
