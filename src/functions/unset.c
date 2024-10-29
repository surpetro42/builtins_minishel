/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:20:10 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/29 17:49:02 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_node(t_duplicate_env *env, char *s)
{
	(void)env;
	t_duplicate_env	*start = NULL;
	char			**str;
	int				i;
	
	i = 0;
	str = ft_split(s, ' ');
	start = env;
	while (str[i])
	{
		while (env)
		{
			if (env->key && ft_strcmp(env->key, str[i]) == 0)
			{
				env->key = NULL;
				env->value = NULL;
			}
			env = env->next;
		}
		env = start; 
		i++;
	}
} 

void	unset_f(utils_t *utils, char *str)
{
	delete_node(utils->shell->duplicate_env, str);
}