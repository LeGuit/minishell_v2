/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:35:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 10:35:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_cd(char **args)
{
	if (args[1] == NULL || args[1] = '~')
		chdir(HOME);
	else
	{
		if (chdir(args[1] != 0))
			ft_error_chdir(args[1]);
	}
	return (1);
}

int				sh_help(char **args)
{
	int			i;
	ft_putendl("Gwoodwar Minishell");
	ft_putendl("Type program names and arguments, press enter.");
	ft_putendl("Here are the built in:");
	i = 0;
	while (i < sh_nb_builtin())
	{
		ft_printf("%5s,\n", builtin_str[i]);
		i++;
	}
	return (1);
}

int				sh_exit(char ** args)
{
	return (0);
}
