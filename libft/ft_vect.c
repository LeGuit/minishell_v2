/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:02:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/12 16:30:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_vect_push_back(t_vect *vect, void *buf)
{
	void		*tmp;

	if (vect->capacity == vect->size)
	{
		tmp = vect->data;
		vect->capacity = (vect->capacity ? vect->capacity * 2 : 1);
		vect->data = malloc(vect->capacity * vect->element_size);
		if (!vect->data)
			return (1);
		vect->data = ft_memcpy(vect->data, tmp, vect->size);
		free(tmp);
	}
	vect->data = ft_memcpy((vect->data + (vect->size * vect->element_size)),
			buf, vect->element_size);
	vect->size++;
	return (0);
}

int				ft_vect_reserve(t_vect *vect, size_t reserve)
{
	void		*tmp;

	if (reserve <= vect->capacity)
		return (1);
	tmp = vect->data;
	vect->data = malloc(reserve * vect->element_size);
	if (!vect->data)
		return (1);
	vect->data = ft_memcpy(vect->data, tmp, vect->size);
	free(tmp);
	vect->capacity = reserve;
	return (0);
}

int				ft_vect_del(t_vect *vect, int (*del)(void *))
{
	if (del(vect->data))
		return (1);
	vect = NULL;
	return (0);
}
