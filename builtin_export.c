/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_xport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:20:18 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:20:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		export_replace(char *name, char **env)
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

int				sh_export(t_info *info, char **env, char **args)
{
	char		name[1024];
	int			i;

	(void)info;
	i = 0;
	while (args[i])
	{
		ft_bzero(name, 1024);
		ft_strcpy(name, args[i]);
		if (export_replace(name, env))
			ft_addenv(args[i], env);
		i++;
	}
	return (EXIT_SUCCESS);
}