/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:32:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 16:10:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				init_info(t_info *info)
{
	info->line = NULL;
	info->args = NULL;
	info->status = 0;
}

void				sh_tild_to_home(t_info *info)
{
	char			*res;
	int				i;

	i = 0;
	while (info->args[i][0] != '~')
		i++;
	res = sh_get_in_env("HOME", info->env);
	if (res)
	{
		free(info->args[i]);
		info->args[i] = ft_strdup(res);
	}
}
