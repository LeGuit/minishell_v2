/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_toolsold.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:27:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:16:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	
	ft_printf("SH_ADD arg[0]: %s\targ[1]: %s\n", info->args[0], info->args[1]);
}
