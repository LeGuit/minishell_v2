/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:19:34 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/18 17:20:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_env(t_info *info, char **env, char **args)
{
	int			index;
	int			test;

	(void)env;
	if (!args[0])
		sh_printenv(info, env, args);
	else
	{
		index = 0;
		while ((test = env_opt(args[index], info)) > 0)
			index++;
		if (test == -1)
			return (EXIT_FAILURE);
		else
			ft_env(info, &args[index]);
	}
	return (EXIT_FAILURE);
}
