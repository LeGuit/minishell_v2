/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:55:18 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 15:45:59 by gwoodwar         ###   ########.fr       */
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
	char			*cursdir;
	char			**env;
}					t_info;

int					sh_loop(void);
int					sh_get_line(t_info *info);
void				sh_parse(t_info *info);
int					sh_launch(t_info *info);
int					sh_exec(t_info *info);
void				sh_get_path(t_info *info);
char				*sh_get_in_env(const char *name, char **env);
char				**sh_getenv(char **environ);
void				sh_tild_to_home(t_info *info);


int					sh_nb_builtin(void);

int					sh_cd(t_info *info);
int					sh_help(t_info *info);
int					sh_exit(t_info *info);
int					sh_pwd(t_info *info);
int					sh_printenv(t_info *info);

int					ft_error_malloc(void);
int					ft_error_fork(t_info *info);
int					ft_error_execv(char *illdir);
int					ft_error_chdir(char *arg);

extern char			**environ;
extern char			*g_builtin_str[];
extern int			(*g_builtin_fct[])(t_info *info);
void				init_info(t_info *info);

void				free_tab(char **tab);
#endif
