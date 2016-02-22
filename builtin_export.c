/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_xport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:20:18 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/22 10:19:46 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_export(t_info *info, char **env, char **args)
{
	char		name[1024];
	int			i;

	(void)env;
	i = 0;
	if (!args[0])
		sh_printenv(info, env, args);
	while (args[i])
	{
		if (!ft_strchr(args[i], '='))
			break ;
		ft_bzero(name, 1024);
		ft_strcpy(name, args[i]);
		if (ft_replaceenv(name, info->env))
			ft_addenv(args[i], &info->env);
		i++;
	}
	return (EXIT_SUCCESS);
}
