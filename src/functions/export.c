/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:19:45 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/28 16:18:23 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// _________________________________________________________________________________________________________

void	input_export(t_shell *shell, char **str)
{
	t_duplicate_env	*start;
	t_duplicate_env	*last;
	t_duplicate_env	*new_node;
	int				i;
	int				findEl;
 
	i = 0;
	start = shell->duplicate_env;

	last = shell->duplicate_env;
	while (last && last->next)
		last = last->next;

	while (str[i])
	{
		findEl = find(str[i]);
		if (findEl == -1)
			break ;
		new_node = (t_duplicate_env *)malloc(sizeof(t_duplicate_env));
		if (!new_node)
			return ;
		new_node->key = ft_substr(str[i], 0, findEl);
		if (find_space(str[i]) == 2)
			new_node->value = ft_substr(str[i], findEl + 1, ft_strlen(str[i]));
		else
			new_node->value = NULL;
		new_node->next = NULL;
		if (last)
			last->next = new_node;
		else
			start = new_node;
		last = new_node;
		i++;
	}
	shell->duplicate_env = start;
}
// _________________________________________________________________________________________________________

int	validation_variable(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			count++;
		i++;
	}
	i = 0;
	if (count > 0)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
				|| s[i] == '_' )
		{
			while (s[++i])
			{
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
					|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
					return (0);
			}
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

void	add_enviorment(t_shell *shell)
{
	t_duplicate_env	*start;

	start = shell->duplicate_env;
	while (shell->duplicate_env)
	{
		printf("%s=", shell->duplicate_env->key);
		printf("%s\n", shell->duplicate_env->value);
		shell->duplicate_env = shell->duplicate_env->next;
	}
	shell->duplicate_env = start;
}

void	export_f(utils_t *utils, char *s)
{
	t_duplicate_env	*env;
	t_duplicate_env	*start;
	char			**str;

	env = utils->shell->duplicate_env;
	str = ft_split(s, ' ');
	if(!str)
	{
		free(str);
		exit(0);
	}	
	input_export(utils->shell, str);
	start = utils->shell->duplicate_env;
	while (utils->shell->duplicate_env)
	{
		if (validation_variable(utils->shell->duplicate_env->key) == 0)
		{
			utils->shell->duplicate_env->key = NULL;
			utils->shell->duplicate_env->value = NULL;
		}
		utils->shell->duplicate_env = utils->shell->duplicate_env->next;
	}
	utils->shell->duplicate_env = start;
	add_enviorment(utils->shell);
}