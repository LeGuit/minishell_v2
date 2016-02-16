/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:24:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/08 11:28:43 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			dlst_cut_position(t_dlst *nlst, t_dlst *head, t_dlst *entry)
{
	t_dlst		*tmp;

	if (dlst_empty(head))
		return ;
	if (dlst_is_singular(head) && (head->next != entry && head != entry))
		return ;
	if (entry == head)
		dlst_init(nlst);
	else
	{
		tmp = entry->next;
		nlst->next = head->next;
		nlst->next->prev = nlst;
		nlst->prev = entry;
		entry->next = nlst;
		head->next = tmp;
		tmp->prev = head;
	}
}

void			dlst_merge(t_dlst *heada, t_dlst *headb,
		int (*cmp)(t_dlst *, t_dlst *))
{
	t_dlst		*ita;
	t_dlst		*itb;

	ita = heada->next;
	while (!dlst_empty(headb))
	{
		itb = headb->next;
		if (cmp(ita, itb) > 0)
		{
			dlst_del_entry(itb);
			dlst_add(itb, ita->prev, ita);
		}
		else
		{
			ita = ita->next;
			if (ita == heada)
				break ;
		}
	}
	while (!dlst_empty(headb))
	{
		dlst_del_entry(itb);
		dlst_add_tail(itb, heada);
		itb = headb->next;
	}
}

t_dlst			*dlst_go_to(t_dlst *head, int nb)
{
	t_dlst		*it;

	it = head->prev;
	while (nb)
	{
		it = it->prev;
		nb--;
	}
	return (it);
}

void			dlst_merge_sort(t_dlst *head, int (*cmp)(t_dlst *, t_dlst *))
{
	t_dlst		newlst;
	int			size;

	if (dlst_is_singular(head) || dlst_empty(head))
		return ;
	dlst_init(&newlst);
	size = dlst_size(head) / 2;
	dlst_cut_position(&newlst, head, dlst_go_to(head, size));
	dlst_merge_sort(head, cmp);
	dlst_merge_sort(&newlst, cmp);
	dlst_merge(head, &newlst, cmp);
}

void			dlst_rev(t_dlst *head)
{
	t_dlst		*it;
	t_dlst		*tmp;

	it = head->next;
	while (it != head)
	{
		tmp = it->next;
		it->next = it->prev;
		it->prev = tmp;
		it = it->prev;
	}
	tmp = head->next;
	head->next = head->prev;
	head->prev = tmp;
}
