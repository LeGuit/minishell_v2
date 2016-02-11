/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:38:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 17:51:14 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*sh_fetch_in_path(char *path, char *cmd)
{
	int			i;
	char		*tmp;
	char		*tmpath;
	char		*cursor;
	struct stat	statfile;

	tmpath = path;
	while (tmpath)
	{
		ft_putstr(tmpath);
		i = 0;
		tmp = NULL;
		cursor = tmpath;
		ft_putstr("YO");
		while (tmpath[i] != ':')
			i++;
		ft_putstr("YO");
		tmp = ft_strncpy(tmp, cursor, i);
		ft_putstr("BITCH");
		ft_putstr(tmp);
		tmp = ft_strcat(tmp, "/");
		tmp = ft_strcat(tmp, cmd);
		lstat(tmp, &statfile);
		if (!statfile.st_mode & S_IXUSR)
			ft_error_chdir(cmd);
		else if (access(tmp, 0))
			ft_error_chdir(cmd);
		else
			return (tmp);
		tmpath = (ft_strchr(tmpath, ':') + 1);
	}
	ft_error_chdir(cmd);
	return (NULL);
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

int				sh_launch(t_info *info)
{
	pid_t		pid;
	pid_t		wpid;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		if (sh_execve(info) == -1)
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
