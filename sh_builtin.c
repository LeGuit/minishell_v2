/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:35:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/10 17:48:51 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int			(*builtin_fct[]) (char **) = {
	&sh_cd,
	&sh_help,
	&sh_exit
};

int			sh_cd(char **args)
{
	if (args[1] == NULL)
		chdir(HOME);
	else
	{
		if (chdir(args[1] != 0))
			ft_error_chdir(args[1]);
	}
	return (1);
}
