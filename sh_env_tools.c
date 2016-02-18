/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:24:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/18 17:23:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_getenv(const char *name, char **env)
{
	int			i;
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
	int			sizename;

	if (!name || !env)
		return (EXIT_FAILURE);
	j = 0;
	sizename = ft_strlen(name);
	while (env[j])
	{
		if (!ft_strncmp(env[j], name, sizename) && env[j][sizename] == '=')
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

int				ft_replaceenv(const char *name, char **env)
{
	int			i;
	int			sizename;

	if (!name || !env)
		return (1);
	i = 0;
	sizename = ft_strlen_ch(name, '=');
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, sizename) && env[i][sizename] == '=')
		{
			free(env[i]);
			env[i] = ft_strdup(name);
			break ;
		}
		i++;
	}
	if (env[i])
		return (0);
	return (1);
}

int				ft_addenv(const char *newenv, char ***env)
{
	char		**tmp;
	size_t		size;
	int			i;

	if (!newenv || !env)
		return (EXIT_FAILURE);
	tmp = *env;
	size = ft_tabsize(*env);
	ft_printf("sizetab: %d\n", size);
	*env = (char **)malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (tmp[i])
	{
		(*env)[i] = tmp[i];
		i++;
	}
	(*env)[size] = ft_strdup(newenv);
	(*env)[size + 1] = 0;
	free(tmp);
	return (EXIT_SUCCESS);
}
