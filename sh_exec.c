/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:38:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 17:16:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		sh_execve(t_info *info)
{
	char		buf[PATH_MAX];
	char		*envpath;
	char		defpath[14];
	int			error;

	ft_strcpy(defpath, "/bin:/usr/bin");
	if (!(envpath = sh_get_in_env("PATH", info->env)))
		envpath = defpath;
	error = resolve_path(info->args[0], envpath, buf);
	if (!error && !(error = ft_access(buf)))
		execve(buf, info->args, info->env);
	ft_error(error, info->args[0]);
	exit(EXIT_FAILURE);
}

static int		status_checker(int status, char *cmd)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (ft_error_status(WTERMSIG(status), cmd));
	return (EXIT_FAILURE);
}

int				sh_launch(t_info *info, char **env)
{
	pid_t		pid;
	pid_t		wpid;
	int			status;

	pid = fork();
	if (pid < 0)
		ft_error_fork(info);
	else
	{
		if (pid == 0)
			sh_execve(info);
		wpid = waitpid(pid, &status, WUNTRACED);
		return (status_checker(status, info->args[0]));
	}
	return (1);
}
