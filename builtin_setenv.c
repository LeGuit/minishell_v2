/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:21:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:29:05 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		setenv_replace(char *name, char **env)
{
	int			i;
	int			sizename;

	i = 0;
	sizename = ft_strlen_ch(name, '=');
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, sizename) && env[i][sizename] == '=')
		{
			ft_replaceenv(name, env[i]);
			break ;
		}	
		i++;
	}
	if (env[i])
		return (0);
	return (1);
}

int				sh_setenv(t_info *info, char **env, char **args)
{
	char		name[1024];
	int			i;

	(void)info;
	i = 0;
	while (args[i])
	{
		ft_bzero(name, 1024);
		ft_strcpy(name, args[i]);
		ft_strcat(name, "=");
		if (args[i + 1])
		{
			ft_strcat(name, args[i + 1]);
			i++;
		}
		if (setenv_replace(name, env))
			ft_addenv(name, env);
		i++;
	}
	return (EXIT_SUCCESS);
}