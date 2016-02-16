/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 12:14:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_unsetenv(t_info *info)
{
	int			i;
	int			j;

	if (!info->args[1])
		return (EXIT_SUCCESS);
	j = 0;
	while (info->args[j])
	{
		if (sh_get_in_env(info->args[j], info->env))
		{
			i = 0;
			while (ft_strncmp(info->env[i], info->args[j],
						ft_strlen(info->args[j])) && info->env[i])
				i++;
			while (info->env[i] != 0)
			{
				info->env[i] = info->env[i + 1];
				i++;
			}
		}
		j++;
	}
	sh_printenv(info);
	return (EXIT_SUCCESS);
}

int				sh_setenv(t_info *info)
{
	int			i;

	i = 1;
	while (info->args[i])
	{
		if (ft_strchr(info->args[i], '='))
			sh_setenv_eq(info, i);
		else if (info->args[i + 1])
		{
			sh_setenv_sp(info, i);
			i++;
		}
		else if (!GET(info->sig, ENV_Y))
		{
			ft_printf("setenv: %s: No such file or directory\n", info->args[i]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (!GET(info->sig, ENV_Y))
		sh_printenv(info);
	return (EXIT_SUCCESS);
}

static void		sh_context(t_info *info, t_info *context)
{
	context->line = ft_strdup(info->line);
	context->args = ft_tabdup(info->args);
	context->env = ft_tabdup(info->env);
	context->status = info->status;
	context->sig = info->sig;
	context->cursdir = ft_strdup(info->cursdir);
	ft_strcpy(context->path, info->path);
}

static void		sh_clear_context(t_info *context)
{
	free(context->line);
	if (context->args)
		ft_tabdel(&context->args);
	if (context->env)
		ft_tabdel(&context->env);
	free(context->cursdir);
}

int				sh_env(t_info *info)
{
	int			i;
	t_info		context;

	sh_context(info, &context);
	UNSET(context.opt, OPT_A);
	i = 1;
	while (env_opt(context.args[i], &context))
		i++;
	if (GET(context.opt, OPT_I))
		env_i(&context, i);
	else if (!context.args[1])
	{
		sh_printenv(&context);
		return (EXIT_SUCCESS);
	}
	else
		env_set(&context);
	if (ft_strequ(context.args[0], "cd"))
		return (EXIT_SUCCESS);
	else if (context.args[0])
		sh_exec(&context);
	else
		sh_printenv(&context);
	sh_clear_context(&context);
	return (EXIT_SUCCESS);
}
