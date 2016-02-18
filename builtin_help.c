/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:18:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/18 17:21:00 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_help(t_info *info, char **env, char **args)
{
	int			i;

	(void)info;
	(void)env;
	(void)args;
	ft_putendl("Gwoodwar Minishell");
	ft_putendl("Type program names and arguments, press enter.");
	ft_putendl("Here are the built in:");
	i = 0;
	while (i < sh_nb_builtin())
	{
		ft_printf("     %s,\n", g_builtin_str[i]);
		i++;
	}
	return (1);
}
