/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:29:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 11:42:58 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		sh_echo_n(t_info *info)
{
	int			i;

	i = 2;
	while (info->args[i + 1])
	{
		ft_printf("%s ", info->args[i]);
		i++;
	}
	ft_printf("%s", info->args[i]);
}

int				sh_echo(t_info *info)
{
	int			i;

	if (!info->args[1])
		ft_putchar('\n');
	else
	{
		if (ft_strequ(info->args[1], "-n"))
			sh_echo_n(info);
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
	}
	return (EXIT_SUCCESS);
}
