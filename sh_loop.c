/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/10 12:28:19 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_info(t_info *info)
{
	info->line = NULL;
	info->args = NULL;
	info->status = 0;
}

void			sh_get_line(t_info *info)
{
	char		*tmpline;
	char		*forfree;

	while (get_next_line(0, &tmpline))
	{
		forfree = info->line;
		info->line = ft_strjoin(info->line, tmpline);
		if (forfree != NULL)
			free(forfree);
		free(tmpline);
	}
}

void		sh_

int				sh_loop(void)
{
	t_info		info;

	init_info(&info);
	ft_putendl("$> ");
	sh_get_line(&info);
	sh_parse(&info);
	sh_exec(&info);
	free(info.line);
	free(info.args);
	while (info.status);
	return (EXIT_SUCCESS);
}
