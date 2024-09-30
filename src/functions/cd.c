/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:26:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/30 15:54:36 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	search_fole(t_duplicate_env *env, char *s)
{
	char cwd[PATH_MAX];
	char *str;

	if (getcwd(cwd, PASS_MAX) == NULL)
		return;
	str = ft_strdup(s);
	if (str[0] == '~' || str[0] < 32)
	{
		changes_old_env(&env, cwd);
		if (home(env) == NULL)
			exit(0);
		chdir(home(env));
		getcwd(cwd, PATH_MAX);
		changes_env(&env, cwd);
		return ;
	}
	else if(str[0] > 32)
	{
		if (check_directory(str) == 0)
			return ;
		if (access_directory(str) == 0)
		{
			printf("minishell: %s: ", s);
			printf("Permission denied\n");
			return;
		}
		changes_old_env(&env, cwd);
		chdir(str);
		getcwd(cwd, PATH_MAX);
		changes_env(&env, cwd);
		return;
	}
}

void	cd(t_shell *shell)
{
	int i = 0;
	int buff = 0;


	while (shell->input[i])
	{
		if (shell->input[i] == 'c' && shell->input[i + 1] == 'd' && shell->input[i + 2] == ' ')
		{
			buff = i;
			buff += 3;
			search_fole(shell->duplicate_env, &shell->input[buff]);
		}
		else if (shell->input[i] == 'c' && shell->input[i + 1] == 'd' && shell->input[i + 1] <= 32)
		{
			home(shell->duplicate_env);
			if (home(shell->duplicate_env) == NULL)
				exit(0);
			chdir(home(shell->duplicate_env));
		}
		else if (shell->input[i] == 'c' && shell->input[i + 1] == 'd' && shell->input[i + 2] > 32)
			printf("command not found\n");
		i++;
	}
}
