/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 16:28:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_get_line(t_info *info)
{
	int			retgnl;

	retgnl = get_next_line(0, &info->line);
	if (retgnl == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	sh_get_path(info);
	ft_printf("\033[31m%s\033[39m $> ", info->cursdir);
	if (sh_get_line(info))
		return (EXIT_FAILURE);
	sh_parse(info);
	info->status = sh_exec(info);
	free(info->line);
	free_tab(info->args);
	while (info->status)
		sh_loop(info);
	return (EXIT_SUCCESS);
}
