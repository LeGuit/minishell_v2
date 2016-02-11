/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 10:54:56 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 11:01:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft/includes/libft.h"
# define PATH_SIZE	4096

typedef struct		s_info
{
	char			*line;
	char			**args;
	int				status;
	char			path[PATH_SIZE];
	char			*ptrpath;
	char			*cursdir;
}					t_info;

int					sh_loop(void);
int					sh_get_line(t_info *info);
void				sh_parse(t_info *info);
int					sh_launch(t_info *info);
int					sh_exec(t_info *info);
void				sh_get_path(t_info *info);

int					sh_nb_builtin(void);

int					sh_cd(char **args);
int					sh_help(char **args);
int					sh_exit(char **args);

int					ft_error_malloc(void);
int					ft_error_fork(t_info *info);
int					ft_error_execv(t_info *info);
int					ft_error_chdir(char *arg);

extern char			*g_builtin_str[];
extern int			(*g_builtin_fct[])(char **);
void				init_info(t_info *info);

void				free_tab(char **tab);
#endif
