/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:51:02 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 14:49:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sh_get_path(t_info *info)
{
	int			i;

	ft_bzero(info->path, PATH_SIZE);
	getcwd(info->path, PATH_SIZE - 1);
	if (ft_strchr(info->path, '/'))
	{
		i = ft_strlen(info->path);
		while (i--)
		{
			if (info->path[i] == '/')
				break ;
		}
		info->cursdir = &(info->path[i + 1]);

	}
	else
		info->cursdir = info->path;
}
