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
		if (ft_replaceenv(name, env))
			ft_addenv(args[i], &env);
		i++;
	}
	return (EXIT_SUCCESS);
}