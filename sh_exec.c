/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:38:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 15:28:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static char		*sh_fetch_in_path(char *path, char *cmd)
{
	int			i;
	char		*res;

	i = 0;
	res = NULL;
	while (path[i])
	{
		if (path[i] == ':')
		{
			path = &path[i];
			i = 0;
		}
		if (ft_strequ(&path[i], cmd))
		{
			res = path;
			break ;
		}
		i++;
	}
	return (res);
}

static int		sh_execve(t_info *info)
{
	int			retexec;
	char		*path;

	if (info->args[0][0] == '/')
		retexec = execve(info->args[0], info->args, info->env);
	else
	{
		path = sh_get_in_env("PATH", info->env);
		path = sh_fetch_in_path(path, info->args[0]);
		retexec = execve(path, info->args, info->env);
	}
	return (retexec);
}
*/
int				sh_launch(t_info *info)
{
	pid_t		pid;
	pid_t		wpid;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(info->args[0], info->args, environ) == -1)
			ft_error_execv(info->args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_error_fork(info);
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
