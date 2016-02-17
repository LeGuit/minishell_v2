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

int				sh_cd(t_info *info, char **env, char **args)
{
	char		*path;
	char		*oldpath;

	if (args[0] == NULL)
	{
		path = sh_get_in_env("HOME", env);
		chdir(path);
	}
	else if (ft_strequ(args[0], "-"))
	{
		path = sh_get_in_env("OLDPWD", env);
		chdir(path);
	}
	else
	{
		if (chdir(args[0]) != 0)
			ft_error_chdir(args[0]);
	}
	oldpath = ft_strjoin("OLDPWD=", info->path);
	sh_replace_env(oldpath, env);
	free(oldpath);
	return (1);
}