/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jamanakavor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:10 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/24 01:08:53 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_strcmp_space(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] != ' ' && s2[i] != ' ' && s1[i] == s2[i])
	{
		i++;
	}
	if(s1[i] == ' ')
		i--;
	return (s1[i] - s2[i]);
}

static int	count_words(char const *s, char x)
{
	int i = 0;
	int	count;

	count = 0;
	while (s[i])
	{
		if(s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
		}
		if (s[i] != x)
		{
			count++;
			while (s[i] && s[i] != x)
				i++;
		}
		else
			++i;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int			res_count;
	char		**str;
	int			i;
	const char	*p_s;

	if (!s)
		return (NULL);
	res_count = count_words(s, c);
	str = (char **)malloc((res_count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < res_count)
	{
		while (*s == c)
		{
			if(*s == '"')
			{
				s++;
				while (*s && *s != '"')
					s++;
			}
			if(*s)
				s++;
		}
		if(s)
			p_s = s;
		while (*s && *s != c)
		{
			if(*s == '"')
			{
				s++;
				while (*s && *s != '"')
					s++;
			}
			if(*s)
				s++;
		}
		str[i] = ft_substr(p_s, 0, s - p_s);
		if (!str[i] && ft_split(*str, i))
			return (NULL);
	}
	str[i] = NULL;
	return (str);
}
