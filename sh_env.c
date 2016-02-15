/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 11:30:16 by gwoodwar         ###   ########.fr       */
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
	return (0);
}
/*
int			sh_setenv(t_info *info)
{

}*/
