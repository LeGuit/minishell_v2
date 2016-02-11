/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 16:09:37 by gwoodwar         ###   ########.fr       */
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
	sizename = ft_strlen(name) - 1;
	i = 0;
	res = NULL;
	while (env[i] != 0)
	{
		if ((res = ft_strchr(env[i], '=')))
		{
			ft_printf("env: %d\tressize: %d\tsizename: %d\tres: %s\n", ft_strlen(env[i]), ft_strlen(res), sizename, res);
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
