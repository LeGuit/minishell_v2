/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:53:08 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 14:31:29 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(void)
{
	t_info	info;

	init_info(&info);
	sh_sig_init(&info);
	sh_loop(&info);
	ft_putendl("exit");
	return (EXIT_SUCCESS);
}
