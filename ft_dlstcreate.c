/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:06:55 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 13:36:22 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		dlst_init(t_dlst *dlst)
{
	dlst->next = dlst;
	dlst->prev = dlst;
}

void		dlst_add(t_dlst *new, t_dlst *prev, t_dlst *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

void		dlst_add_head(t_dlst *new, t_dlst *dlst)
{
	dlst_add(new, dlst, dlst->next);
}

void		dlst_add_tail(t_dlst *new, t_dlst *dlst)
{
	dlst_add(new, dlst->prev, dlst);
}
