/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:42:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 18:16:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_i(t_info *context, int nbopt)
{
	char		**tmp;

	ft_tabdel(&context->env);
	tmp = context->args;
	context->args = ft_tabdup(context->args + nbopt + 1);
	ft_tabdel(&tmp);
}

void			env_set(t_info *context)
{
	int			i;
	char		**tmp;

	if (ft_strchr(context->args[1], '='))
	{
		SET(context->sig, ENV_Y);
		sh_setenv(context);
		tmp = context->args;
		i = 0;
		while (ft_strchr(context->args[i], '='))
			i++;
		context->args = ft_tabdup(context->args + i);
		ft_tabdel(&tmp);
	}
}

/*
void			env_u(t_info *context)
{
	int			i;

	free(context->args[0]);
	free(context->args[1]);
	i = 2;
	while (context->args[i])
	{
		context->args[i - 2] = context->args[i];
		i++;
	}
	sh_unsetenv(context);
	free(context->args[0]);
	i = 1;
	while (context->args[i])
	{
		context->args[i - 1] = context->args[i];
		i++;
	}
	context->args[i] = 0;
}*/
