/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <gwoodwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:20:18 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 19:20:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_exit(t_info *info)
{
	(void)info;
	ft_putendl("EXIT SUCCESS");
	exit(EXIT_SUCCESS);
}