/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:44:26 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/22 00:20:20 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*c_add(char *s, char c)
{
	int		s1_i;
	char	*con;

	if(!c)
		return (NULL);
	s1_i = 0;
	con = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1 + 1));
	if (!con)
		return (NULL);
	while (s && s[s1_i] != '\0')
	{
		con[s1_i] = s[s1_i];
		s1_i++;
	}
	con[s1_i] = c;
	s1_i++;
	con[s1_i] = '\0';
	if (s)
		free (s);
	return (con);
}

int key_variable_number(char *s)
{
	int		i;

	i = 0;
	if(s[i] >= '0' && s[i] <= '9')
		i++;
	return i;
}

char	*variable(char *str)
{
	int		i = 0;
	int		l = 0;
	char	*res;
	if(str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
		i++;
	res = malloc(sizeof(char *) *i + 1);
	i = 0;
	while (str[++i])
		res[l++] = str[i];
	res[l] = '\0';
	return (res);
}

char	*open_dollar(char *key, t_duplicate_env *duplicate_env)
{
	int		i;
	int		value_len;
	char	*res_buff = NULL;
	char	*res_line = NULL;
	char	*buff;
	t_duplicate_env *start = duplicate_env;

	i = 0;
	while (key && key[i])
	{
		value_len = 0;
		if(key[i] == '$' && key[i + 1] > 32)
		{
			i++;
			buff = ft_strndup(&key[i]);
			buff = ft_strtrim(buff, " ");
			if(!(key_variable_number(buff) > 0))
			{
				while (duplicate_env)
				{
					if (ft_strcmp(buff, duplicate_env->key) == 0)
					{
						res_buff = ft_strdup(duplicate_env->value); 
						break;
					}
					duplicate_env = duplicate_env->next;
				}
				i += ft_strlen(buff);
				duplicate_env = start->next;
				res_line = ft_strjoin(res_line, res_buff);
				res_line = ft_strjoin(res_line, " ");
				if (res_buff == NULL)
					free(res_buff);
			}
		}
		else
		{
			if (key[i])
				res_line = c_add(res_line, key[i]);
		}
		if (key[i])
			i++;
	}
	return res_line;
}

char	*dollar(char *str, utils_t *utils)
{
	char	*res_line_key = NULL;

	res_line_key = open_dollar(str, utils->shell->duplicate_env);
	printf("%s\n", res_line_key);
	return res_line_key;
}
