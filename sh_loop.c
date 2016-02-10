/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/10 17:32:34 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_info(t_info *info)
{
	info->line = NULL;
	info->args = NULL;
	info->status = 0;
}

int				sh_get_line(t_info *info)
{
	char		*tmpline;
	char		*forfree;
	int			retgnl;

	while ((retgnl = get_next_line(0, &tmpline)))
	{
		if (retgnl == -1)
			return (EXIT_FAILURE);
		forfree = info->line;
		info->line = ft_strjoin(info->line, tmpline);
		if (forfree != NULL)
			free(forfree);
		free(tmpline);
	}
	forfree = info->line;
	info->line = ft_strtrim(info->line);
	free(forfree);
	return (EXIT_SUCCESS);
}

void		sh_parse(t_info *info)
{
	int		i;

	i = 0;
	while (info->line[i])
	{
		if (info->line[i] == '\t' || info->line[i] == '\n'
			|| info->line[i] == '\r' || info->line[i] == '\a')
			info->line[i] = ' ';
	}
	info->args = ft_strsplit(info->line, ' ');
}

int				sh_exec(t_info *info)
{
	extern char	**environ;
	pid_t		pid;
	pid_t		wpid;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(info->args[0], info->args, environ) == -1)
		{
			ft_error_execv(info);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		ft_error_fork(info);
		return (EXIT_FAILURE);
	}
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

int				sh_loop(void)
{
	t_info		info;

	init_info(&info);
	sh_get_path(&info);
	ft_printf("%s$> ", info.cursdir);
	if(sh_get_line(&info))
		return (EXIT_FAILURE);
	sh_parse(&info);
	sh_exec(&info);
	free(info.line);
	free_tab(info.args);
	while (info.status);
	return (EXIT_SUCCESS);
}
