/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:27:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 15:26:43 by gwoodwar         ###   ########.fr       */
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
	while (env[i] != 0)
	{
		if ((res = ft_strchr(env[i], '=')))
		{
			if (((ft_strlen(env[i]) - ft_strlen(res)) == sizename
						&& !ft_strncmp(env[i], name, sizename)))
				break ;
		}
		i++;
	}
	if (env[i] == 0)
		return (NULL);
	res++;
	return (res);
}

char			**sh_getenv(char **environ)
{
	int			i;
	char		**env;

	i = 0;
	while (environ[i])
		i++;
	if (!(env = (char **)malloc(sizeof(char *) * (i + 1))))
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

void			sh_replace_env(char *args, char **env)
{
	size_t		sarg;
	int			i;

	sarg = ft_strlen_ch(args, '=');
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(args, env[i], sarg))
		{
			free(env[i]);
			env[i] = ft_strdup(args);
		}
		i++;
	}
}

void			sh_add_env(char *args, t_info *info)
{
	char		**tmp;
	int			i;

	tmp = info->env;
	i = 0;
	while (tmp[i])
		i++;
	info->env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tmp[i])
	{
		info->env[i] = tmp[i];
		i++;
	}
	free(tmp);
	info->env[i] = ft_strdup(args);
	info->env[i + 1] = 0;
}
