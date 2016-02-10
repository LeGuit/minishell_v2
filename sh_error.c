/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:54:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/10 16:37:35 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_error_malloc(void)
{
	ft_putstr_fd("minishell: Out of memory", 2);
	return (EXIT_FAILURE);
}

int					ft_error_execv(t_info *info)
{
	(void)info;
	ft_putstr_fd("minishell: Execv error", 2);
	return (EXIT_FAILURE);
}

int					ft_error_fork(t_info *info)
{
	(void)info;
	ft_putstr_fd("minishell: Fork error", 2);
	return (EXIT_FAILURE);
}
