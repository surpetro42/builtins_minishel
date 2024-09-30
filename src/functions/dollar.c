/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:44:26 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/27 15:35:04 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	dollar(t_shell *shell)
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
