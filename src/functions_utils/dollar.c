/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:13:15 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/07 20:33:47 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_strlen_first_word(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] > 32)
		i++;
	return i;
}

char	*ft_strdup_first_word(char *s1)
{
	size_t	i;
	size_t	x;
	char	*m;

	i = 0;
	x = ft_strlen_first_word(s1);
	m = (char *)malloc(x + 1);
	if (m == NULL)
		return (NULL);
	while (i < x)
	{
		m[i] = s1[i];
		++i;
	}
	if (i == x)
		m[i] = '\0';
	return (m);
}
