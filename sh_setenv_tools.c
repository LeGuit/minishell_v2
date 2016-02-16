/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:56:48 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 12:09:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sh_setenv_eq(t_info *info, int i)
{
	char		name[1024];

	ft_bzero(name, 1024);
	ft_strncpy(name, info->args[i], ft_strlen_ch(info->args[i], '='));
	if ((sh_get_in_env(name, info->env)))
		sh_replace_env(info->args[i], info->env);
	else
		sh_add_env(info->args[i], info);
}

void			sh_setenv_sp(t_info *info, int i)
{
	char		name[1024];

	ft_bzero(name, 1024);
	ft_strcpy(name, info->args[i]);
	ft_strcat(name, "=");
	if ((sh_get_in_env(name, info->env)))
	{
		ft_strcat(name, info->args[i + 1]);
		sh_replace_env(name, info->env);
	}
	else
	{
		ft_strcat(name, info->args[i + 1]);
		sh_add_env(name, info);
	}
}
