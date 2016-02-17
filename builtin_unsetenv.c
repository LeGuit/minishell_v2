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

int				sh_unsetenv(t_info *info, char **env, char **args)
{
	int			i;

	i = 0;
	while (arg[i])
	{
		ft_unsetenv(arg[i], env);
		i++;
	}
	return (EXIT_SUCCESS);
}