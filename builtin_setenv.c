/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:21:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/18 17:21:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		test_alpha(char *arg)
{
	int			i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int				sh_setenv(t_info *info, char **env, char **args)
{
	char		name[1024];

	if (!args[0])
		sh_printenv(info, env, args);
	else if (args[1] && args[2])
		ft_putendl_fd("sh_setenv: Too many arguments.", 2);
	else if (test_alpha(args[0]))
		ft_putendl_fd("sh_setenv: Variable name must contain"
		" alphanumeric characters.", 2);
	else
	{
		ft_bzero(name, 1024);
		ft_strcpy(name, args[0]);
		ft_strcat(name, "=");
		if (args[1])
			ft_strcat(name, args[1]);
		ft_printf("SETENV >> name: %s\n", name);
		if (ft_replaceenv(name, info->env))
			ft_addenv(name, &info->env);
	}
	return (EXIT_SUCCESS);
}
