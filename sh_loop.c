/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 11:52:27 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_get_line(t_info *info)
{
	char		*forfree;
	int			retgnl;

	retgnl = get_next_line(0, &info->line);
	if (retgnl == -1)
		return (EXIT_FAILURE);
	forfree = info->line;
	info->line = ft_strtrim(info->line);
	free(forfree);
	return (EXIT_SUCCESS);
}

void			sh_parse(t_info *info)
{
	int		i;

	i = 0;
	while (info->line[i])
	{
		if (info->line[i] == '\t' || info->line[i] == '\n'
				|| info->line[i] == '\r' || info->line[i] == '\a')
			info->line[i] = ' ';
		i++;
	}
	info->args = ft_strsplit(info->line, ' ');
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
			return ((*g_builtin_fct[i])(info->args));
		i++;
	}
	return (sh_launch(info));
}

int				sh_loop(void)
{
	t_info		info;

	init_info(&info);
	sh_get_path(&info);
	ft_printf("%s$> ", info.cursdir);
	if (sh_get_line(&info))
		return (EXIT_FAILURE);
	sh_parse(&info);
	info.status = sh_exec(&info);
	free(info.line);
	free_tab(info.args);
	while (info.status)
		sh_loop();
	return (EXIT_SUCCESS);
}
