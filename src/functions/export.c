/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:19:45 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/24 23:03:57 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// _________________________________________________________________________________________________________

int	find_space(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '"')
			count++;
		i++;
	}
	return (count);
}

void	input_export(t_shell *shell, char **str)
{
	t_input_export	*iter;
	t_input_export	start;
	int				i;
	int				findEl;
 
	i = 0;
 	iter = &start;
	while (str[i])
	{
		findEl = find(str[i]);
		if(findEl == -1)
			break;
		iter->next = malloc(sizeof(t_input_export));
		iter->next->key = ft_substr(str[i], 0, findEl);
		if (find_space(str[i]) == 2)
			iter->next->value = ft_substr(str[i], findEl + 1, ft_strlen(str[i]));
		else
			iter->next->value = NULL;
		iter = iter->next;
		i++;
	}
	iter->next = NULL;
	shell->input_export = start.next;
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
	if(count > 0)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
				|| s[i] == '_' )
		{
			i++;
			while (s[i])
			{
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
					|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
					return (0);
				i++;
			}
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

// void	validation_str(char **)
// {
	
// }

void	add_enviorment(t_shell *shell)
{
	while (shell->duplicate_env)
		shell->duplicate_env = shell->duplicate_env->next;

	while (shell->input_export)
	{
		printf("shell->input_export->key == %s\n", shell->input_export->key);
		printf("shell->input_export->value == %s\n", shell->input_export->value);
		shell->input_export = shell->input_export->next;
	}
}

void	export_f(utils_t *utils, char *s)
{
	t_duplicate_env	*env;
	t_input_export	*start;
	char			**str;

	env = utils->shell->duplicate_env;
	str = ft_split(s, ' ');
	input_export(utils->shell, str);
	start = utils->shell->input_export;
	while (utils->shell->input_export)
	{
		if (validation_variable(utils->shell->input_export->key) == 0)
		{
			utils->shell->input_export->key = NULL;
			utils->shell->input_export->value = NULL;
		}
		validation_variable(utils->shell->input_export->key);
		utils->shell->input_export = utils->shell->input_export->next;
	}
	utils->shell->input_export = start;
	add_enviorment(utils->shell);
}