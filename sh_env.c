/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 15:28:46 by gwoodwar         ###   ########.fr       */
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
		else
		{
			ft_printf("setenv: %s: No such file or directory\n", info->args[i]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	sh_printenv(info);
	return (EXIT_SUCCESS);
}

static void		sh_context(t_info *info, t_info *context)
{
	int			i;

	context->line = ft_strdup(info->line);
	i = 0;
	while (info->args[i])
		i++;
	context->args = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (info->args[++i])
		context->args[i] = ft_strdup(info->args[i]);
	context->args[i] = 0;
	i = 0;
	while (info->env[i])
		i++;
	context->env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (info->env[++i])
		context->env[i] = ft_strdup(info->env[i]);
	context->env[i] = 0;
	context->status = info->status;
	context->sig = info->sig;
	context->cursdir = ft_strdup(info->cursdir);
	ft_strcpy(context->path, info->path);
}

static void		sh_clear_context(t_info *context)
{
	free(context->line);
	free_tab(context->args);
	free_tab(context->env);
	free(context->cursdir);
}

int				sh_env(t_info *info)
{
	t_info		context;
	int			i;

	sh_context(info, &context);
	if (ft_strequ(context.args[1], "-u"))
	{
		free(context.args[1]);
		i = 1;
		while (context.args[i])
		{
			context.args[i] = context.args[i + 1];
			i++;
		}
		sh_unsetenv(&context);
	}
	else
		sh_printenv(&context);
	sh_clear_context(&context);
	return (EXIT_SUCCESS);
}
