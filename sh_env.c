/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:42:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/16 18:52:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				sh_env(t_info *info)
{	
	int			index;
	char		**context;

	index = 1;
	while (getopt_env(info->line, info);//need to exit &&index is after all -i can exit cause no malloc ?
		index++;
	context = ft_tabdup(info->env);
	if (GET(info->opt, OPT_I)
		env_i(context);
	index += env_u(&info->args[index], context);//test -u of nothing or -u with no =
	while (ft_strchr(info->args[index], '='))
	{
		sh_setenv(info->args[index], context);//care about env null
		index++;
	}
	sh_exec(&info->args[index]);
	ft_tabdel(&context);
	return (EXIT_FAILURE);
}

void			env_i(char **env)
{
	char		**tmp;
	int			index;

	ft_tabdel(&env);
	env = (char **)malloc(sizeof(char *) * 1);
	env[0] = ft_strdup("\0");
}

void			env_u(char **args, char **env)
{
	int			i;
	int			index;

	i = 0;
	while (ft_strequ(args[i], "-u"))
	{
		i++;
		sh_unsetenv(args[i], env);
		i++;
		index +=2;
	}
	return (index);
}
