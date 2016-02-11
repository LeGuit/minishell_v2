/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:57:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 19:31:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int				sh_get_line(t_info *info)
{
	int			retgnl;

	if (retgnl == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
i*/
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
	ft_printf("%s\t%s\t%s\n", info->args[0], info->args[1], info->args[2]);
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

	ret = 1;
	sh_get_path(info);
	ft_printf("\033[31m%s\033[39m $> ", info->cursdir);
	while ((ret = get_next_line(0, &info->line)) > 0)
	{
		ft_printf("ytkhgfkhj");
//		sh_parse(info);
	//	info->status = sh_exec(info);
		free(info->line);
	}
//	free_tab(info->args);
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
