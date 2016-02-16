/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:56:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 17:02:51 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void			ft_error_status(int status, char *cmd)
{
	if (status == SIGSEGV)
		ft_putstr_fd("[1] segmentation fault  ", 2);
	else if (status == SIGBUS)
		ft_putstr_fd("[1] bus error  ", 2);
	ft_putendl_fd(cmd, 2);
}
