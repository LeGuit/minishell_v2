/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_printenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:15:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:17:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_printenv(t_info *info)
{
	int			i;

	i = 0;
	while (info->env[i])
	{
		ft_putendl(info->env[i]);
		i++;
	}
	return (1);
}