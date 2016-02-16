/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:22:05 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 15:49:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int				ft_access(char *path)
{
	struct stat	statfile;

	if (access(path, F_OK) == -1)
		return (ENOENT);
	lstat(path, &statfile);
	if (S_ISDIR(statfile.st_mode))
		return (EISDIR);
	if (access(path, X_OK) == -1)
		return (EACCES);
	return (0);
}
