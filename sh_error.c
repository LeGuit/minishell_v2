/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:54:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 18:43:13 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_error_malloc(void)
{
	ft_putendl_fd("minishell: Out of memory", 2);
	exit(EXIT_FAILURE);
}

int					ft_error_execv(char *illdir)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(illdir, 2);
	return (EXIT_FAILURE);
}

int					ft_error_fork(t_info *info)
{
	(void)info;
	ft_putendl_fd("minishell: Fork error", 2);
	return (EXIT_FAILURE);
}

int					ft_error_chdir(char *illdir)
{
	struct stat		statfile;

	ft_putstr_fd("sh_cd: ", 2);
	if (stat(illdir, &statfile) == -1)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (!(S_ISDIR(statfile.st_mode)))
		ft_putstr_fd("not a directory: ", 2);
	else if (!(statfile.st_mode & (S_IXUSR)))
		ft_putstr_fd("permission denied: ", 2);
	ft_putendl_fd(illdir, 2);
	return (EXIT_FAILURE);
}

int			ft_error_parse(char illopt)
{
	ft_putstr_fd("sh_env: illegal option -- ", 2);
	ft_putchar_fd(illopt, 2);
	ft_putstr_fd("\nusage: sh_env [-i] [-u name]\n", 2);
	ft_putstr_fd("              [name = value]"
			" [utility [argument ...]]\n", 2);
	return (1);
}
