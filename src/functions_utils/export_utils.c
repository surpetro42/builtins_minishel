/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:57:25 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/28 17:12:57 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_space(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '=')
			if(!(s[i + 1] ==	'"'))
				return 0;
		if (s[i] == '"')
			count++;
		i++;
	}
	return (count);
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

char **spit_cycle(int res_count, char const *s, char c, char **str)
{
	int			i;
	const char	*p_s;

	i = -1;
	while (++i < res_count)
	{
		while (*s == c)
		{
			if (*s == '"')
			{
				s++;
				while (*s && *s != '"')
					s++;
			}
			if (*s)
				s++;
		}
		if(s)
			p_s = s;
		while (*s && *s != c)
		{
			if (*s == '"')
			{
				s++;
				while (*s && *s != '"')
					s++;
			}
			if (*s)
				s++;
		}
		str[i] = ft_substr(p_s, 0, s - p_s);
		if (!str[i] && ft_split(*str, i))
			return (NULL);
	}
	str[i] = NULL;
	return (str);

}

char	**ft_split(char const *s, char c)
{
	int			res_count;
	char		**str;

	if (!s)
		return (NULL);
	res_count = count_words(s, c);
	str = (char **)malloc((res_count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = spit_cycle(res_count, s, c, str);
	return (str);
}
