/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:44:26 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/25 21:49:18 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

int	find(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	len_afterdollar(char *s)
{
	int i = 0;
	while (s[i] > 32)
		i++;
	return (i);
}

void	search_key(t_duplicate_env *duplicate_env, char *s)
{
	int i = 0;

	while (duplicate_env->next)
	{
		if(ft_strstr(s, duplicate_env->key))
		{
			while (duplicate_env->value[i])
			{
				write(1, &duplicate_env->value[i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
		duplicate_env = duplicate_env->next;
	}
}

void	search(t_shell *shell)
{
	int i = 0;
	int l = 0;
	
	while (shell->input[i])
	{
		l = 0;
		if(shell->input[i] == '$')
			search_key(shell->duplicate_env ,&shell->input[i]);
		i++;
	}
}

int	dollar(t_shell *shell, char **env)
{
	t_duplicate_env	*iter;
	t_duplicate_env	start;
	int				i;
	int				l;
	int				k;
	int				v;

	i = 0;
	l = 0;
	k = 0;
	v = 0;
	iter = &start;
	while (env[i])
	{
		int findEl = find(env[i]);
		iter->next = malloc(sizeof(t_duplicate_env));
		iter->next->key = ft_substr(env[i], 0, findEl);
		iter->next->value = ft_substr(env[i], findEl + 1, ft_strlen(env[i]));
		iter = iter->next;
		i++;
	}
	iter->next = NULL;
	shell->duplicate_env = start.next;
	search(shell);
	return (0);
}
