/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:29:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 15:30:11 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_echo(t_info *info)
{
	int			i;

	if (ft_strequ(info->args[1], "-n"))
	{
		i = 2;
		while (info->args[i + 1])
		{
			ft_printf("%s ", info->args[i]);
			i++;
		}
		ft_printf("%s", info->args[i]);
	}
	else
	{
		i = 1;
		while (info->args[i + 1])
		{
			ft_printf("%s ", info->args[i]);
			i++;
		}
		ft_printf("%s\n", info->args[i]);
	}
	return (EXIT_SUCCESS);
}
