/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:42:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 18:52:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_i(char **env)
{
	ft_tabdel(&env);
	env = (char **)malloc(sizeof(char *) * 1);
	env[0] = ft_strdup("\0");
}

int				env_u(char **args, char **env)
{
	int			i;
	int			index;

	i = 0;
	index = 0;
	while (ft_strequ(args[i], "-u"))
	{
		i++;
		ft_unsetenv(args[i], env);
		i++;
		index +=2;
	}
	return (index);
}

int				ft_env(t_info *info, char **args)
{
	int			index;	
	char		**context;

	index = 0;
	context = ft_tabdup(info->env);
	if (GET(info->opt, OPT_I))
		env_i(context);
	index += env_u(&args[index], context);//test -u of nothing or -u with no =
	while (ft_strchr(args[index], '='))
	{
		sh_export(info, context, &args[index]);//care about env null
		index++;
	}
	sh_exec(info, context, &args[index]);
	ft_tabdel(&context);
	return (EXIT_FAILURE);
}