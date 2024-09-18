/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:26:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/18 18:02:52 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/headershell.h"

int	ft_strlen(const char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return i;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;	

	i = 0;
	destination = (char *)dst;
	source = (const char *)src;
	if (!dst && !src)
		return (	NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (str1 == NULL)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, str1, len1);
	ft_memcpy(result + len1, str2, len2 + 1);
	return (result);
}

void search_fole(char *s)
{
	int i = 0;
	char cwd[PATH_MAX];
	char *key;
	
	if(getcwd(cwd, PATH_MAX) == NULL)
		return ;
	int fd = open(&s[0] , O_RDONLY);
	printf("%s\n", &s[0]);
	if (fd < 0)
	{
		printf("sxala buhahahaha");
		exit(1);
	}
 	if (chdir(&s[0]) == -1)
	{
        perror("chdir() error");
        return ;
    }
	if (getcwd(cwd, PATH_MAX) != NULL) 
		printf("%s\n", cwd);
	else if (chdir(".") == -1)
	{
        perror("chdir() error");
        return ;
    }
}

void validation_cd(char **str)
{
	int i = 1;
	int l = 0;

	while (str[i])
	{
		l = 0;
		while (str[i][l])
		{
			if (str[i][l] == 'c' && str[i][l + 1] == 'd' && str[i][l + 2] == ' ')
			{
				l += 3;
				search_fole(&str[i][l]);
			}
			else if (str[i][l] == 'c' && str[i][l + 1] == 'd' && str[i][l + 2] > 32)
				printf("command not found\n");
			
			l++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	validation_cd(argv);
	return 0;
}