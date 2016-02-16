/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:16:05 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:17:34 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_cd(t_info *info)
{
	char		*path;
	char		*oldpath;

	if (info->args[1] == NULL)
	{
		path = sh_get_in_env("HOME", info->env);
		chdir(path);
	}
	else if (ft_strequ(info->args[1], "-"))
	{
		path = sh_get_in_env("OLDPWD", info->env);
		chdir(path);
	}
	else
	{
		if (chdir(info->args[1]) != 0)
			ft_error_chdir(info->args[1]);
	}
	oldpath = ft_strjoin("OLDPWD=", info->path);
	sh_replace_env(oldpath, info->env);
	free(oldpath);
	return (1);
}