/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:07:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/20 19:42:22 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		dlst_del(t_dlst *prev, t_dlst *next)
{
	next->prev = prev;
	prev->next = next;
}

void		dlst_del_entry(t_dlst *entry)
{
	dlst_del(entry->prev, entry->next);
}

void		dlst_replace(t_dlst *old, t_dlst *new)
{
	new->next = old->next;
	new->prev = old->prev;
	new->prev->next = new;
	new->next->prev = new;
}

void		dlst_replace_init(t_dlst *old, t_dlst *new)
{
	dlst_replace(old, new);
	dlst_init(old);
}

void		dlst_del_init(t_dlst *entry)
{
	dlst_del_entry(entry);
	dlst_init(entry);
}
