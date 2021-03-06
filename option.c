/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:29:30 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/18 17:29:31 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		invalid_opt(char option, t_info *info)
{
	if (!(ft_strchr("i", option)))
		return (1);
	if (option == 'i')
		SET(info->opt, OPT_I);
	return (0);
}

int				env_opt(char *line, t_info *info)
{
	size_t		i;

	if (!line)
		return (0);
	if (line[0] != '-')
		return (0);
	if (ft_strequ(line, "--"))
		return (0);
	if (ft_strequ(line, "-u"))
		return (0);
	if (line[0] == '-' && line[1] == '\0')
		return (0);
	i = 1;
	while (i < ft_strlen(line))
	{
		if (invalid_opt(line[i], info))
			ft_error_parse(line[i]);
		i++;
	}
	return (1);
}
