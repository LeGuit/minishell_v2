/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c 	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:29:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:20:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_env(t_info *info, char **env, char **args)
{
	int			index;
	int			test;

	(void)env;
	index = 1;
	while ((test = env_opt(info->line, info)) > 0)//need to exit &&index is after all -i can exit cause no malloc ?
		index++;
	if (test == -1)
		return (EXIT_FAILURE);
	else
		ft_env(info, &args[index]);
	return (EXIT_FAILURE);

}