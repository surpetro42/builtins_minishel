/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:03:36 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/01 22:19:50 by surpetro         ###   ########.fr       */
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
	char	**str_split;
	int		i;
	int		cd_res;

	utils = malloc(sizeof(utils_t));
	utils->shell = malloc(sizeof(t_shell));
	utils->shell->duplicate_env = NULL;

	i = 0;

	duplicate_env(utils->shell, env);
	while (1)
	{
		str = readline("\033[38;5;43mminishell: \033[0;000m");
		add_history(str);
		if (ft_strcmp(str, "pwd") == 0)
			pwd(utils);

		if (ft_strcmp_space(str, "echo") == 0)
		{
			str_split = ft_split(str, ' ');
			echo(str_split , utils);
		}
		dollar(str, utils);
		cd_res = cd(str, utils);
		// env_print(shell);
		// ft_execve(shell, env);
	}
	return 0;
}
