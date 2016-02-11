/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:51:02 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 10:47:56 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sh_get_path(t_info *info)
{
	int			i;

	ft_bzero(info->path, PATH_SIZE);
	info->ptrpath = getcwd(info->path, PATH_SIZE - 1);
	if (ft_strchr(info->ptrpath, '/'))
	{
		i = ft_strlen(info->ptrpath);
		while (i--)
		{
			if (info->ptrpath[i] == '/')
				break ;
		}
		info->cursdir = &(info->path[i + 1]);
	}
	else
		info->cursdir = info->ptrpath;
}
