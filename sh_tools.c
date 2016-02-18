/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:32:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 11:16:53 by gwoodwar         ###   ########.fr       */
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
	while (info->args[i])
	{
		if (info->args[i][0] == '~'
				&& (info->args[i][1] == '/' || info->args[i][1] == 0))
		{
			res = ft_getenv("HOME", info->env);
			if (res)
			{
				res = ft_strjoin(res, info->args[i] + 1);
				free(info->args[i]);
				info->args[i] = res;
			}
		}
		i++;
	}
}
