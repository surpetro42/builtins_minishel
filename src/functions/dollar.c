/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:44:26 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/07 20:47:24 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_variable(char *s, t_duplicate_env *duplicate_env)
{
	int i;

	i = 0;
	
	if(s[i] >= '0' && s[i] <= '9')
		i++;
	while (duplicate_env->next)
	{
		if (ft_strcmp(&s[i], duplicate_env->key) == 0) 
			return 1;
		duplicate_env = duplicate_env->next;
	}
	return 0;
}

int	dollar_validation(char *s)
{
	int	i;

	i = 0;
	if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_' )
	{
		i++;
		while (s[i])
		{
			if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
				return 0;
			i++;
		}
	}
	else
		return 0;
	return 1;
}

char	*search_key(t_duplicate_env *duplicate_env, char *s)
{
	char *str;
	int i = 0;

	if (s[i] >= '0' && s[i] <= '9')
		return &s[++i];
	while (duplicate_env->next)
	{
		if (ft_strcmp(&s[i], duplicate_env->key) == 0)
		{
			str = ft_strdup(duplicate_env->value);
			return (str);
		}
		else if (ft_strcmp(&s[i], "$") == 0)
			return (s);
		duplicate_env = duplicate_env->next;
	}
	return NULL;
}

char	*dollar(char *str, utils_t *utils)
{
	int		i = 0;
	char	*key;
	char	*res;
	int		valid_res;
	int		is_var;

	res = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			key = ft_strdup_first_word(&str[i]);
			valid_res = dollar_validation(key);
			is_var = is_variable(key, utils->shell->duplicate_env);
			if (is_var == 0)
				break ;
			if (valid_res == 1)
				res = search_key(utils->shell->duplicate_env ,key);
		}
		i++;
	}
	if (res != NULL)
		printf("%s\n", res);
	return res;
}
