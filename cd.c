/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:26:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/18 22:14:56 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/headershell.h"
#include <stdio.h>

int key_strlen(char *s)
{
	int i = 0;

	while (s && s[i] > 32)
		i++;
	return i;
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	x;
	char	*m;

	i = 0;
	x = key_strlen(s1);
	m = (char *)malloc(x + 1);
	if (m == NULL)
		return (NULL);
	while (i < x)
	{
		m[i] = s1[i];
		++i;
	}
	if (i == x)
		m[i] = '\0';
	return (m);
}

int	access_directory(char *s)
{
	printf("%s\n", s);
	if (access(s, R_OK | X_OK) == 0)
		return (1);
	else
		return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char *home(t_duplicate_env *env)
{
		// printf("---------------******\n");
	printf("ehhhhhh\n");
	while (env)
	{
		// printf("---------------%d\n", ft_strcmp(env->key, "HOME"));
		if(ft_strcmp(env->key, "HOME") > 0)
			return env->key;
		env = env->next;
	}
	return (NULL);
}

void	search_fole(t_duplicate_env *env, char *s)
{
	int i = 0;
	int fd;
	char cwd[PATH_MAX];
	char *str;
	
	if(getcwd(cwd, PASS_MAX) == NULL)
		return;
	str = ft_strdup(s);

	if(str[0] == '~')
	{
		if (home(env) == NULL)
			exit(0);
	}
	if (access_directory(str) == 0)
		perror("ERROR DOSTUPCHKA");
	if(getcwd(cwd, PASS_MAX) != NULL)
		printf("%s\n", cwd);
}

void validation_cd(t_duplicate_env *env, char **str)
{
	int i = 1;
	int l = 0;

	while (str[i])
	{
		l = 0;
		while (str[i][l])
		{
			if (str[i][l] == 'c' && str[i][l + 1] == 'd' && str[i][l + 2] == ' ')
			{
				l += 3;
				search_fole(env, &str[i][l]);
			}
			else if (str[i][l] == 'c' && str[i][l + 1] == 'd' && str[i][l + 2] > 32)
				printf("command not found\n");
			l++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_duplicate_env *env;
	validation_cd(env, argv);
	return 0;
}