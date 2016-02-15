/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 20:21:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_unsetenv(t_info *info)
{
	int			i;

	if (sh_get_in_env(info->args[1], info->env))
	{
		i = 0;
		while (ft_strncmp(info->env[i], info->args[1],
					ft_strlen(info->args[1])) && info->env[i])
			i++;
		while (info->env[i] != 0)
		{
			info->env[i] = info->env[i + 1];
			i++;
		}
	}
	sh_printenv(info);
	return (EXIT_SUCCESS);
}

int				sh_setenv(t_info *info)
{
	int			i;
	char		name[128];

	i = 1;
	while (info->args[i])
	{
		if (ft_strchr(info->args[i], '='))
		{
			ft_bzero(name, 128);
			ft_strncpy(name, info->args[i], ft_strlen_ch(info->args[i], '='));
			if ((sh_get_in_env(name, info->env)))
				sh_replace_env(info->args[i], info->env);
			else
				sh_add_env(info->args[i], info);
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
	{ft_printf("OPT I");
		env_i(&context, i);}
	else
	{ft_printf("NO OPT");
		env_set(&context);
	}
	ft_printf("arg[0]: %s\n", context.args[0]);
	if (ft_strequ(context.args[0], "cd"))
		return (EXIT_SUCCESS);
	else if (context.args[0])
	{ft_putendl("ARGS");
		sh_exec(&context);}
	else
	{ft_putendl("NO ARGS");
		sh_printenv(&context);}
	sh_clear_context(&context);
	return (EXIT_SUCCESS);
}
