/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 18:34:47 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_multi(t_info *info)
{
	int			i;

	if (!ft_strchr(info->line, ':'))
		return (0);
	i = 0
	while (info->line[i])
	{
		if (info->line[i])
			info->line[i] = '\0';
		i++;
	}
	while ((info->line = ft_strchr(info->line, '\0') + 1))
	{
		sh_parse(info);
		info->status = sh_exec(info);
	}
	return (1);
}

void			sh_parse(t_info *info)
{
	int		i;
	int		tild;

	i = 0;
	tild = 0;
	while (info->line[i])
	{
		if (info->line[i] == '\t' || info->line[i] == '\n'
				|| info->line[i] == '\r' || info->line[i] == '\a')
			info->line[i] = ' ';
		if (info->line[i] == '~')
			tild = 1;
		i++;
	}
	info->args = ft_strsplit(info->line, ' ');
	if (tild == 1)
		sh_tild_to_home(info);
}

int				sh_exec(t_info *info)
{
	int			i;

	if (info->args[0] == NULL)
		return (1);
	i = 0;
	while (i < sh_nb_builtin())
	{
		if (ft_strcmp(info->args[0], g_builtin_str[i]) == 0)
			return ((*g_builtin_fct[i])(info));
		i++;
	}
	return (sh_launch(info));
}

int				sh_loop(t_info *info)
{
	int ret;
	int	multi;

	ret = 1;
	sh_get_path(info);
	ft_printf("\033[31m%s\033[39m $> ", info->cursdir);
	while ((ret = get_next_line(0, &info->line)) > 0)
	{
		UNSET(info->sig, BIT_A);
		if (!(multi = sh_multi(info)))
		{
			sh_parse(info);
			info->status = sh_exec(info);
		}
		sh_get_path(info);
		if (!GET(info->sig, SIG_C))
			ft_printf("\033[31m%s\033[39m $> ", info->cursdir);
		ft_tabdel(&info->args);
		free(info->line);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
