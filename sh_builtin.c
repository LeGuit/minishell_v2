/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:35:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 12:34:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_cd(char **args)
{
	if (args[1] == NULL || ft_strcmp(args[1], "~") == 0)
		chdir("HOME");
	else
	{
		if (chdir(args[1]) != 0)
			ft_error_chdir(args[1]);
	}
	return (1);
}

int				sh_help(char **args)
{
	int			i;

	(void)args;
	ft_putendl("Gwoodwar Minishell");
	ft_putendl("Type program names and arguments, press enter.");
	ft_putendl("Here are the built in:");
	i = 0;
	while (i < sh_nb_builtin())
	{
		ft_printf("     %s,\n", g_builtin_str[i]);
		i++;
	}
	return (1);
}

int				sh_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}
