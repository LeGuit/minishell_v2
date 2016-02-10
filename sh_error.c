/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:54:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/10 11:57:20 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_error_malloc(void)
{
	ft_putstr_fd("minishell: Out of memory", 2);
	return (EXIT_FAILURE);
}
