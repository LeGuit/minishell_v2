/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 10:25:47 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*sh_get_in_env(const char *name, char **env)
{
	int			i;
	char		*res;
	size_t		sizename;

	if (env == NULL)
		env = environ;
	sizename = ft_strlen(name);
	i = 0;
	res = NULL;
	while (env[i] != 0)
	{
		if ((res = ft_strchr(env[i], '=')))
		{
			if (((ft_strlen(env[i]) - ft_strlen(res)) == sizename
					   && !ft_strncmp(env[i], name, sizename)))
				break;
		}
		i++;
	}
	res++;
	return (res);
}

char		**sh_getenv(char **environ)
{
	int		i;
	char	**env;

	i = 0;
	while (environ[i])
		i++;
	if(!(env = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_error_malloc();
	i = 0;
	while (environ[i])
	{
		if (!(env[i] = ft_strdup(environ[i])))
			ft_error_malloc();
		i++;
	}
	env[i] = 0;
	return (env);
}

int			sh_unsetenv(t_info *info)
{
	int		i;
	

	if (sh_get_in_env(info->args[1], info->env))
	{
		i = 0;
		while (ft_strncmp(info->env[i], info->args[1] , ft_strlen(info->args[1]))
				&& info->env[i])
			i++;
		while (info->env[i] != 0)
		{
			info->env[i] = info->env[i + 1];
			i++;
		}
	}
	sh_printenv(info);
	return (0);
}
