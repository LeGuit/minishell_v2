/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:21:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:16:35 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_unsetenv(t_info *info)
{
	int			i;

	i = 1;
	while (info->arg[i])
	{
		ft_unsetenv(info->arg[i], info->env);
		i++;
	}
	return (EXIT_SUCCESS);
}