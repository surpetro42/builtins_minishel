/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:26:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/25 20:50:27 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int key_strlen(char *s)
{
	int i = 0;

	while (s && s[i] > 32)
		i++;
	return i;
}

// ----------------------------- popoxel env -----------------------------

void	changes_old_env(t_duplicate_env **env, char *cwd)
{
	t_duplicate_env *iter;
	
	iter = *env;
	while (*env)
	{
		
		if (ft_strcmp( (*env)->key, "OLDPWD") == 0)
		{
			free((*env)->value); 
			(*env)->value = ft_strdup(cwd);
		}
		*env = (*env)->next;
	}
	*env = iter;
}

void	changes_env(t_duplicate_env **env, char *cwd)
{
	t_duplicate_env *iter;
	
	iter = *env;
	while (*env)
	{
		if(ft_strcmp( (*env)->key, "PWD") == 0)
		{
			free((*env)->value); 
			(*env)->value = ft_strdup(cwd);
		}
		*env = (*env)->next;
	}
	*env = iter;
}

// ----------------------------- popoxel env -----------------------------

int	access_directory(char *s)
{
	if (access(s, R_OK | X_OK) == 0)
		return (1);
	else
		return (0);
}

char	*home(t_duplicate_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, "HOME") == 0)
			return env->value;
		env = env->next;
	}
	return (NULL);
}

int	check_directory(char *s)
{
	struct stat fileStat;

	if(stat(s, &fileStat) < 0)
	{
		printf("minishell: %s: ", s);
		printf("No such file or directory\n");
		return 0;
	}
	return 1;
}

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
		return;
	}
	else if(str[0] > 32)
	{
		if(check_directory(str) == 0)
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

void cd(t_shell *shell)
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
		else if (shell->input[i] == 'c' && shell->input[i + 1] == 'd' && shell->input[i + 2] > 32)
			printf("command not found\n");
		i++;
	}
}
