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

void			env_set(t_info *context)
{
	int			i;
	char		**tmp;

	ft_printf("arg[0]: %s\targ[1]: %s\n", context->args[0], context->args[1]);
	if (ft_strchr(context->args[1], '='))
	{
		SET(context->sig, ENV_Y);
		sh_setenv(context);
	ft_printf("arg[0] after setenv: %s\targ[1]: %s\n", context->args[0], context->args[1]);
		tmp = context->args;
		i = 0;
		while (ft_strchr(context->args[i], '='))
		{
			i++;
			if (!context->args[i])
				break ;
		}
		context->args = ft_tabdup(&context->args[i]);
		ft_tabdel(&tmp);
	}
	else
	{
		tmp = context->args;
		context->args = ft_tabdup(&context->args[1]);
		ft_tabdel(&tmp);
	}
	ft_printf("arg[0] after setenv: %s\targ[1]: %s\n", context->args[0], context->args[1]);
}