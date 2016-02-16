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

void			env_i(t_info *context, int nbopt)
{
	char		**tmp;
	int			i;

	ft_tabdel(&context->env);
	tmp = context->args;
	i = nbopt;
	while (context->args[i])
		i++;
	context->args = (char **)malloc(sizeof(char *) * (i + 2));
	context->args[0] = ft_strdup("env");
	i = nbopt;
	while (tmp[i])
	{
		context->args[i - nbopt + 1] = tmp[i];
		i++;
	}
	ft_printf("arg[0]: %s\targ[1]: %s\n", context->args[0], context->args[1]);
	ft_tabdel(&tmp);
}

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
