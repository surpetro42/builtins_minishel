/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:06:39 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/27 14:59:34 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_print(t_shell *shell)
{
	t_duplicate_env	*start;
	int i = 0;
	
	start = shell->duplicate_env;
	if(ft_strcmp(shell->input, "env") == 0)
	{
		while (shell->duplicate_env)
		{
			i = 0;
			while (shell->duplicate_env->key[i])
				write(1, &shell->duplicate_env->key[i++], 1);
			i = 0;
			write(1, "=",1);
			while (shell->duplicate_env->value[i])
				write(1, &shell->duplicate_env->value[i++], 1);
			shell->duplicate_env = shell->duplicate_env->next;
			write(1, "\n",1);
		}
	}
	shell->duplicate_env = start;
}
