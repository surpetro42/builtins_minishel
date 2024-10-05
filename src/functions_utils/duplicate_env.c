/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:13:27 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/05 15:40:38 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	duplicate_env(t_shell *shell, char **env)
{
	t_duplicate_env	*iter;
	t_duplicate_env	start;
	int				i;
	int				findEl;
 
	i = 0;
 	iter = &start;
	while (env[i])
	{
		
		findEl = find(env[i]);
		iter->next = malloc(sizeof(t_duplicate_env));
		if (ft_strcmp(ft_substr(env[i], 0, findEl),  "OLDPWD") == 0)
			i++;
		iter->next->key = ft_substr(env[i], 0, findEl);
		iter->next->value = ft_substr(env[i], findEl + 1, ft_strlen(env[i]));
		iter = iter->next;
		i++;
	}
	iter->next = NULL;
	shell->duplicate_env = start.next;
}