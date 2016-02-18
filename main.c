/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:53:08 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 10:34:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_envcpy(char **environ)
{
	size_t		sizetab;
	char		**env;
	int			i;

	sizetab = ft_tabsize(environ);
	env = (char **)malloc(sizeof(char *) * (sizetab + 1));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	return (env);
}

int				main(void)
{
	t_info		info;
	extern char	**environ;

	init_info(&info);
	info.env = ft_envcpy(environ);
	sh_sig_init(&info);
	sh_loop(&info);
	ft_putendl("exit");
	return (EXIT_SUCCESS);
}
