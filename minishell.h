/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:54:56 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/10 12:24:20 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"

typedef struct		s_info
{
	char			*line;
	char			**args;
	int				status;
}					t_info;

int					sh_loop(void);
void				sh_get_line(t_info *info);
int					sh_parse(t_info *info);
int					sh_exec(t_info *info);

int					ft_error_malloc(void);

#endif
