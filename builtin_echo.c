/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:29:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:20:50 by gwoodwar         ###   ########.fr       */
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

int				sh_echo(t_info *info, char **env, char **args)
{
	int			i;

	(void)env;
	if (!args[0])
		ft_putchar('\n');
	else if (ft_strequ(args[0], "-n") && !args[1])
		;
	else
	{
		if (ft_strequ(args[0], "-n"))
			sh_echo_n(info);
		else
		{
			i = 0;
			while (args[i + 1])
			{
				ft_printf("%s ", args[i]);
				i++;
			}
			ft_printf("%s\n", args[i]);
		}
	}
	return (EXIT_SUCCESS);
}
