/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:42:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 09:47:36 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_i(t_info *context, int nbopt)
{
	char		**tmp;

	ft_tabdel(&context->env);
	tmp = context->args;
	context->args = ft_tabdup(&context->args[nbopt]);
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
		i = 1;
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
}

static int		invalid_opt(char option, t_info *context)
{
	if (!(ft_strchr("i", option)))
		return (1);
	if (option == 'i')
		SET(context->opt, OPT_I);
	return (0);
}

int				env_opt(char *line, t_info *context)
{
	size_t		i;

	if (!line)
		return (0);
	if (line[0] != '-')
		return (0);
	if (ft_strequ(line, "--"))
		return (0);
	if (line[0] == '-' && line[1] == '\0')
		return (0);
	i = 1;
	while (i < ft_strlen(line))
	{
		if (invalid_opt(line[i], context))
			ft_error_parse(line[i]);
		i++;
	}
	return (1);
}
