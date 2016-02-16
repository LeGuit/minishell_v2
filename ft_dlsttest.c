/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsttest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:36:32 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/20 17:58:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			dlst_empty(t_dlst *head)
{
	return (head->next == head);
}

int			dlst_is_last(t_dlst *dlst, t_dlst *head)
{
	return (dlst->next == head);
}

int			dlst_is_singular(t_dlst *head)
{
	return (!dlst_empty(head) && (head->next == head->prev));
}

int			dlst_size(t_dlst *head)
{
	int		count;
	t_dlst	*it;

	count = 0;
	it = head->next;
	while (it != head)
	{
		count++;
		it = it->next;
	}
	return (count);
}
