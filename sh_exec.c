/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:38:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 15:26:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*test_path(char *cursor, char *cmd, int size)
{
	char		*tmp;
	struct stat	statfile;

	tmp = ft_strnew(ft_strlen(cmd) + size + 1);
	ft_strncpy(tmp, cursor, size);
	tmp = ft_strcat(tmp, "/");
	tmp = ft_strcat(tmp, cmd);
	lstat(tmp, &statfile);
	if (!statfile.st_mode & S_IXUSR)
		return (NULL);
	else if (access(tmp, 0))
		return (NULL);
	else
		return (tmp);
	return (NULL);
}

static char		*sh_fetch_in_path(char *path, char *cmd)
{
	int			i;
	char		*res;
	char		*tmpath;
	char		*cursor;

	tmpath = path;
	while (tmpath)
	{
		i = 0;
		cursor = tmpath;
		while (tmpath[i] != ':')
			i++;
		if ((res = test_path(cursor, cmd, i)))
			return (res);
		free(res);
		tmpath = (ft_strchr(tmpath, ':'));
		if (!tmpath)
			break ;
		tmpath++;
	}
	ft_error_execv(cmd);
	return (NULL);
}

static void		sh_execve(t_info *info)
{
	int			retexec;
	char		*path;
	char		defpath[14];

	if (ft_strchr(info->args[0], '/'))
		retexec = execve(info->args[0], info->args, info->env);
	else
	{
		path = sh_get_in_env("PATH", info->env);
		if (!path)
		{
			ft_strcpy(defpath, "/bin:/usr/bin");
			path = sh_fetch_in_path(defpath, info->args[0]);
		}
		else
			path = sh_fetch_in_path(path, info->args[0]);
		execve(path, info->args, info->env);
	}
	exit(EXIT_SUCCESS);
}

int				sh_launch(t_info *info)
{
	pid_t		pid;
	pid_t		wpid;
	int			status;

	pid = fork();
	if (pid == 0)
		sh_execve(info);
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
