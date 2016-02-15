/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 12:23:19 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			sh_unsetenv(t_info *info)
{
	int		i;
	
	if (sh_get_in_env(info->args[1], info->env))
	{
		i = 0;
		while (ft_strncmp(info->env[i], info->args[1] , ft_strlen(info->args[1]))
				&& info->env[i])
			i++;
		while (info->env[i] != 0)
		{
			info->env[i] = info->env[i + 1];
			i++;
		}
	}
	sh_printenv(info);
	return (EXIT_SUCCESS);
}

int			sh_setenv(t_info *info)
{
	int		i;
	char	name[128];

	i = 1;
	while (info->args[i])
	{
		if (ft_strchr(info->args[i], '='))
		{
			ft_bzero(name, 128);
			ft_strncpy(name, info->args[i], ft_strlen_ch(info->args[i], '='));
			if ((sh_get_in_env(name, info->env)))
				sh_replace_env(info->args[i], info->env);
			else
				sh_add_env(info->args[i], info);
		}
		else
		{
			ft_printf("setenv: %s: No such file or directory\n", info->args[i]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	sh_printenv(info);
	return (EXIT_SUCCESS);
}
