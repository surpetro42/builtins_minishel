/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:03:36 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/08 18:21:16 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	

	if (argc > 1)
		return 1;

	utils_t	*utils;
	char	*str;
	char	*doll;
	// char	**str_split;
	int		i;
	// int		cd_res;

	utils = malloc(sizeof(utils_t));
	utils->shell = malloc(sizeof(t_shell));
	utils->shell->duplicate_env = NULL;

	i = 0;

	duplicate_env(utils->shell, env);
	while (1)
	{
		str = readline("\033[38;5;43mminishell: \033[0;000m");
		ctrl_d(str, utils);
		add_history(str);
		// if (ft_strcmp(str, "pwd") == 0 || ft_strcmp(str, "PWD") == 0)
		// 	pwd(utils);
		// if (ft_strcmp_space(str, "echo") == 0)
		// {
		// 	str_split = ft_split(str, ' ');
		// 	echo(str_split , utils);
		// }
		// if (str[0] == '$')
		// {
			doll = dollar(str, utils);
			// if(doll && ft_strcmp(doll, "PWD") == 0)
				// pwd(utils);
		// }
		// if(str[i] == 'c' && str[i + 1] == 'd')
		// 	cd_res = cd(str, utils);
		// if (ft_strcmp(str, "env") == 0)
			// env_print(utils);
		// if (ft_strcmp(str, "export") == 0)
		// {
			// export_f(utils);
		// }
		// if (ft_strcmp(str, "unset") == 0)
		// ft_execve(shell, env);
	}
	return 0;
}
