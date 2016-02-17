/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:24:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:16:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_getenv(const char *name, char **env)
{
	int			i;
	char		*res;
	size_t		sizename;

	if (!name || !env)
		return (NULL);
	sizename = ft_strlen(name);
	i = 0;
	while (env[i] != 0)
	{
		if (!ft_strncmp(env[i], name, sizename) && env[i][sizename] == '=')
				break ;
		i++;
	}
	if (env[i] == 0)
		return (NULL);
	return (env[i] + sizename + 1);
}

int				ft_unsetenv(const char *name, char **env)
{
	int			i;
	int			j;

	if (!name || !env)
		return (EXIT_FAILURE);
	j = 0;
	sizename = ft_strlen(name);
	while (env[j])
	{
		if (!ft_strncmp(env[i], name, sizename) && env[i][sizename] == '=')
		{
			free(env[j]);
			i = j;
			while (env[i])
			{
				env[i] = env[i + 1];
				i++;
			}
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int				ft_replaceenv(const char *name, char *env)
{
	if (!name || !env)
		return (EXIT_FAILURE);
	free(env);
	env = ft_strdup(name);
}

int				ft_addenv(const char *newenv, char **env)
{
	char		**tmp;
	size_t		size;

	if (!newenv || !env)
		return (EXOT_FAILURE);
	tmp = env;
	size = ft_tabsize(env) + 1;
	env = (char **)malloc(sizeof(char *) * (size + 1));
	ft_tabcpy(env, tmp);
	env[size] = ft_strdup(newenv);
	env[size + 1] = 0;
}