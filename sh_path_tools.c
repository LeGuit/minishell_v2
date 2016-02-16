/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:06:07 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 16:48:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static int		len_path(char *arg, char *buf)
{
	if (ft_strlen(arg) > PATH_MAX - 1)
		return (ENAMETOOLONG);
	ft_strcpy(buf, arg);
	return (0);
}

static int		fetch_path(char *arg, char *envpath, char *buf)
{
	char		*tmpath;
	int			i;

	tmpath = envpath;
	while (tmpath)
	{
		ft_bzero(buf, PATH_MAX);
		i = 0;
		while (tmpath[i] != ':')
			i++;
		if (i + ft_strlen(arg) > PATH_MAX - 1)
			return (ENAMETOOLONG);
		ft_strncpy(buf, tmpath, i);
		ft_strcat(buf, "/");
		ft_strcat(buf, arg);
		if (!ft_access(buf))
			break ;
		if (!(tmpath = ft_strchr(tmpath, ':')))
			break ;
		tmpath++;
	}
	return (0);
}

int				resolve_path(char *arg, char *envpath, char *buf)
{
	if (ft_strchr(arg, '/'))
		return (len_path(arg, buf));
	return (fetch_path(arg, envpath, buf));
}
