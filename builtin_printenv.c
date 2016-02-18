/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_printenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:15:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/18 17:21:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_printenv(t_info *info, char **env, char **args)
{
	int			i;

	(void)info;
	(void)args;
	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
	return (1);
}
