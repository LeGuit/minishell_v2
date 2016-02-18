/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:56:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 17:17:22 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int				ft_error_status(int signal, char *cmd)
{
	if (signal == SIGSEGV)
		ft_putstr_fd("[1] segmentation fault  ", 2);
	else if (signal == SIGBUS)
		ft_putstr_fd("[1] bus error  ", 2);
	else
		ft_putstr_fd("[1] process terminated due to receipt of signal", 2);
	ft_putendl_fd(cmd, 2);
	return (signal);
}
