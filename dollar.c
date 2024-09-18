/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:44:26 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/18 15:03:10 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/headershell.h"

int ft_strlen(const char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

// ------------------------- ft_substr
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*m;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		j = 1;
	else if (s_len < len + start)
		j = s_len - start + 1;
	else
 	m = malloc(sizeof(char) * j);
	if (m == NULL)
		return (NULL);
	while (++i < j - 1)
		m[i] = s[start + i];
	m[i] = '\0';
	return (m);
}
// ------------------------- ft_substr

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


char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	if (!*s2)
		return ((char *)s1);

	i = 0;
	while (s1[i] > 32)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
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
			printf("________ %s\n", duplicate_env->vlue);
		duplicate_env = duplicate_env->next;
	}
}

void	search(t_duplicate_env *duplicate_env, char **s)
{
	int i = 1;
	int l = 0;
	int len;

	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if(s[i][l] == '$')
			{
				l++;
				search_key(duplicate_env ,&s[i][l]);
			}
			l++;
		}
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	t_duplicate_env	*duplicate_env;
	t_duplicate_env	*iter;
	int				i;
	int				l;
	int				k;
	int				v;
	int len_key = 0;
	int len_value = 0;



	i = 0;
	l = 0;
	k = 0;
	v = 0;
	iter = malloc(sizeof(t_duplicate_env));
	duplicate_env  = iter;
	while (env[i])
	{
		int findEl = find(env[i]);
		iter->next = malloc(sizeof(t_duplicate_env));
		iter->key = ft_substr(env[i], 0, findEl);
		iter->vlue = ft_substr(env[i], findEl + 1, ft_strlen(env[i]));
		iter = iter->next;
		i++;
	}
	iter->next = NULL;
	search(duplicate_env ,argv);
	return (0);
}
