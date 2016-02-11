/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 15:29:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*sh_get_in_env(const char *name, char **env)
{
	int			i;
	char		*res;

	if (env == NULL)
		env = environ;
	i = 0;
	res = NULL;
	while (env[i] != 0)
	{
		if (ft_strequ(env[i], name))
		{
			if ((res = (ft_strchr(env[i], '=') + 1)))
				break;
		}
		i++;
	}
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
