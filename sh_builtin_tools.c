/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:16:40 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 14:45:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*g_builtin_str[] =
{
	"cd",
	"help",
	"exit",
	"pwd",
	"echo",
	"printenv",
	"unsetenv",
	"setenv",
	"env",
	"export"
};

int			(*g_builtin_fct[]) (t_info *, char **, char **) =
{
	&sh_cd,
	&sh_help,
	&sh_exit,
	&sh_pwd,
	&sh_echo,
	&sh_printenv,
	&sh_unsetenv,
	&sh_setenv,
	&sh_env,
	&sh_export
};

int			sh_nb_builtin(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}
