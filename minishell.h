/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:55:18 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 20:16:36 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "libft/includes/libft.h"

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/stat.h>
# include <sys/wait.h>

# define PATH_SIZE	4096
# define SIG_C		(1u << 1)
# define ENV_Y		(1u << 2)
# define BIT_A		((1u << 3) - 1)
# define OPT_I		(1u << 1)
# define OPT_MC		(1u << 2)
# define OPT_A		((1u << 3) - 1)

typedef struct		s_info
{
	char			*line;
	char			**args;
	int				status;
	char			path[PATH_SIZE];
	char			*cursdir;
	char			**env;
	int				sig;
	int				opt;
}					t_info;

int					sh_loop(t_info *info);
int					sh_get_line(t_info *info);
void				sh_parse(t_info *info);
int					sh_launch(t_info *info, char **env, char **args);
int					sh_exec(t_info *info, char **env, char **args);
void				sh_get_path(t_info *info);
char				**sh_getenv(char **environ);
void				sh_tild_to_home(t_info *info);
int					ft_access(char *path);
int					resolve_path(char *arg, char *envpath, char *buf);

int					sh_nb_builtin(void);

int					sh_cd(t_info *info, char **env, char **args);
int					sh_help(t_info *info, char **env, char **args);
int					sh_exit(t_info *info, char **env, char **args);
int					sh_pwd(t_info *info, char **env, char **args);
int					sh_echo(t_info *info, char **env, char **args);
int					sh_printenv(t_info *info, char **env, char **args);
int					sh_unsetenv(t_info *info, char **env, char **args);
int					sh_setenv(t_info *info, char **env, char **args);
int					sh_env(t_info *info, char **env, char **args);
int					sh_export(t_info *info, char **env, char **args);
void				sh_setenv_eq(t_info *info, int i);
void				sh_setenv_sp(t_info *info, int i);
int					env_opt(char *line, t_info *context);

int					ft_env(t_info *info, char **args);
int					ft_unsetenv(const char *name, char **env);
int					ft_replaceenv(const char *name, char **env);
int					ft_addenv(const char *newenv, char ***env);
char				*ft_getenv(const char *name, char **env);
void				env_i(char ***env);
int					env_u(char **args, char **env);
void				env_set(t_info *context);

void				ft_error(int error, char *cmd);
int					ft_error_malloc(void);
int					ft_error_fork(t_info *info);
int					ft_error_chdir(char *arg);
int					ft_error_parse(char illopt);
int					ft_error_status(int status, char *cmd);
void				sh_sig_init(t_info *info);

extern char			*g_builtin_str[];
extern int			(*g_builtin_fct[])(t_info *info, char **env, char **args);
void				init_info(t_info *info);
#endif
