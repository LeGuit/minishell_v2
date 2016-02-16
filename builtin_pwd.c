/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:19:32 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:19:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_pwd(t_info *info)
{
	char		buf[4096];

	(void)info;
	ft_bzero(buf, 4096);
	getcwd(buf, 4096);
	ft_putendl(buf);
	return (1);
}