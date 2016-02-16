/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 16:56:13 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		sh_mult_exec(int nbcmd, t_info *info)
{
	while (nbcmd != 0)
	{
		sh_parse(info);
		info->status = sh_exec(info);
		info->line = ft_strchr(info->line, '\0') + 1;
		nbcmd--;
	}
}

static int		sh_multi(t_info *info)
{
	int			i;
	int			count;
	char		*save;

	if (!ft_strchr(info->line, ';'))
		return (0);
	SET(info->opt, OPT_MC);
	i = 0;
	count = 1;
	save = info->line;
	while (info->line[i])
	{
		if (info->line[i] == ';')
		{
			info->line[i] = '\0';
			count++;
		}
		i++;
	}
	sh_mult_exec(count, info);
	info->line = save;
	return (1);
}

void			sh_parse(t_info *info)
{
	int			i;

	i = 0;
	while (info->line[i])
	{
		if (info->line[i] == '\t' || info->line[i] == '\n'
				|| info->line[i] == '\r' || info->line[i] == '\a')
			info->line[i] = ' ';
		i++;
	}
	info->args = ft_strsplit(info->line, ' ');
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
	int			ret;
	int			multi;

	ret = 1;
	sh_get_path(info);
	ft_printf("\033[31m%s\033[39m $> ", info->cursdir);
	while ((ret = get_next_line(0, &info->line)) > 0)
	{
		UNSET(info->sig, BIT_A);
		UNSET(info->opt, OPT_A);
		if (!(multi = sh_multi(info)))
		{
			sh_parse(info);
			info->status = sh_exec(info);
			ft_error_status(info->status,info->args[0]);
		}
		sh_get_path(info);
		ft_printf("\033[31m%s\033[39m $> ", info->cursdir);
		ft_tabdel(&info->args);
		free(info->line);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
