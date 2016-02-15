/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:16:40 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 12:42:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*g_builtin_str[] =
{
	"cd",
	"help",
	"exit",
	"pwd",
	"printenv",
	"unsetenv",
	"setenv",
	"env"
};

int			(*g_builtin_fct[]) (t_info *) =
{
	&sh_cd,
	&sh_help,
	&sh_exit,
	&sh_pwd,
	&sh_printenv,
	&sh_unsetenv,
	&sh_setenv
//	&sh_env
};

int			sh_nb_builtin(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}
