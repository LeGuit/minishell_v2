/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:53:08 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 16:26:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(void)
{
	t_info	info;

	init_info(&info);
	info.env = sh_getenv(environ);
	sh_loop(&info);
	return (EXIT_SUCCESS);
}
