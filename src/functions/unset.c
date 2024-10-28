/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:20:10 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/28 22:48:56 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_node(t_duplicate_env *env, char *str)
{
	t_duplicate_env buff;
	
	if (ft_strcmp(env->key, str) == 0)
	{
		buff.next = env->next;
		free(env);
		env = buff.next;
	}
	while (env)
	{
		if(env->next->next)
			buff.next = env->next->next;
		if (ft_strcmp(env->next->key, str) == 0)
		{
			free(env->next);
			env = buff.next;
	printf("^_^\n");
		}
		env = env->next;
	}
}

void	unset_f(utils_t *utils, char *str)
{
	delete_node(utils->shell->duplicate_env, str);
}