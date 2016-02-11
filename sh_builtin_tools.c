/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:16:40 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 10:47:35 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*g_builtin_str[] =
{
	"cd",
	"help",
	"exit",
	"setenv",
	"unsetenv",
	"env"
};

int			(*g_builtin_fct[]) (char **) =
{
	&sh_cd,
	&sh_help,
	&sh_exit,
	&sh_setenv,
	&sh_unsetenv,
	&sh_env
};

int			sh_nb_builtin(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}
