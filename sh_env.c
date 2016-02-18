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

void			env_i(char ***env)
{
	ft_tabdel(env);
	*env = (char **)malloc(sizeof(char *) * 1);
	*env[0] = 0;
}

int				env_u(char **args, char **env)
{
	int			i;
	int			index;

	if (!args)
		return (0);
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

static void		ft_getcontext(t_info *info, t_info *context)
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

int				ft_env(t_info *info, char **args)
{
	int			index;	
	t_info		context;

	index = 0;
	ft_getcontext(info, &context);
	if (GET(info->opt, OPT_I))
		env_i(&context.env);
	index += env_u(&args[index], context.env);
	while (args[index] && ft_strchr(args[index], '='))
	{
		sh_export(&context, context.env, &args[index]);//care about env null
		index++;
	}
	ft_tabdel(&context.args);
	context.args = ft_tabdup(&args[index]);
	if (args[index])
		sh_launch(&context, context.env, &args[index]);
	sh_clear_context(&context);
	return (EXIT_FAILURE);
}