/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:27:17 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:16:30 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	env_set(&context);
	if (!context.args[0])
		sh_printenv(&context);
	else if (ft_strequ(context.args[0], "cd"))
		;
	else
		sh_exec(&context);
	sh_clear_context(&context);
	return (EXIT_SUCCESS);
}
