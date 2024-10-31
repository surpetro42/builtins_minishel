/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:19:45 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/31 23:08:25 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// _________________________________________________________________________________________________________
// _________________________________________________________________________________________________________
// _________________________________________________________________________________________________________

// int	ft_env_elem_size(t_env_elem *begin_list)
// {
// 	int	count;

// 	count = 0;
// 	while (begin_list)
// 	{
// 		count++;
// 		begin_list = begin_list->next;
// 	}
// 	return (count);
// }

// t_env_elem	*ft_env_elem_at(t_env_elem *begin_list, unsigned int nbr)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < nbr && begin_list->next)
// 	{
// 		begin_list = begin_list->next;
// 		i++;
// 	}
// 	if (i != nbr)
// 		return (NULL);
// 	return (begin_list);
// }

// t_env_elem	*ft_merge_sorted_list(t_env_elem *left, t_env_elem *right,
// 			int (*cmp)())
// {
// 	t_env_elem	dummy;
// 	t_env_elem	*sorted_list;

// 	sorted_list = &dummy;
// 	while (left && right)
// 	{
// 		if ((*cmp)(left->key, right->key) < 0)
// 		{
// 			sorted_list->next = left;
// 			left = left->next;
// 		}
// 		else
// 		{
// 			sorted_list->next = right;
// 			right = right->next;
// 		}
// 		sorted_list = sorted_list->next;
// 	}
// 	if (left)
// 		sorted_list->next = left;
// 	else if (right)
// 		sorted_list->next = right;
// 	return (dummy.next);
// }

// t_env_elem	*merge_sort(t_env_elem *begin_list, int (*cmp)())
// {
// 	t_env_elem	*left;
// 	t_env_elem	*right;
// 	t_env_elem	*pre_right;
// 	int			list_size;

// 	list_size = ft_env_elem_size(begin_list);
// 	if (begin_list == NULL || list_size < 2)
// 		return (begin_list);
// 	left = begin_list;
// 	pre_right = ft_env_elem_at(begin_list, (list_size / 2) - 1);
// 	right = pre_right->next;
// 	pre_right->next = NULL;
// 	left = merge_sort(left, cmp);
// 	right = merge_sort(right, cmp);
// 	return (ft_merge_sorted_list(left, right, cmp));
// }

// void	ft_env_elem_sort(t_env_elem **begin_list, int (*cmp)())
// {
// 	*begin_list = merge_sort(*begin_list, cmp);
// }

// _________________________________________________________________________________________________________
// _________________________________________________________________________________________________________
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

void add_enviorment(t_shell *shell)
{
	t_duplicate_env *start;
	t_input_export *iter;
	t_input_export start1;

	start = shell->duplicate_env;
	iter = &start1;
	while (shell->duplicate_env)
	{
		iter->next = malloc(sizeof(t_input_export));
		iter->key = ft_strdup(shell->duplicate_env->key);
		iter->value = ft_strdup(shell->duplicate_env->value);
		iter = iter->next;
		shell->duplicate_env = shell->duplicate_env->next;
	}
	iter->next = NULL;
	shell->duplicate_env = start;
	shell->input_export = start1.next;
	while (shell->input_export)
	{
		if(shell->input_export->key != NULL)
			printf("%s=", shell->input_export->key);
		else
			printf("%p=", shell->input_export->key);
		if(shell->input_export->value != NULL)
			printf("%s\n", shell->input_export->value);
		else
			printf("%p\n", shell->input_export->value);
		shell->input_export = shell->input_export->next;
		printf("%p\n", shell->input_export);
		// printf("%p\n",shell->input_export);
	}

}

// void	add_enviorment(t_shell *shell)
// {
// 	t_duplicate_env	*start;

// 	start = shell->duplicate_env;
// 	while (shell->duplicate_env)
// 	{
// 		printf("%s=", shell->duplicate_env->key);
// 		printf("%s\n", shell->duplicate_env->value);
// 		shell->duplicate_env = shell->duplicate_env->next;
// 	}
// 	shell->duplicate_env = start;
// }

void	export_f(utils_t *utils, char *s)
{
	t_duplicate_env	*env;
	t_duplicate_env	*start;
	char			**str;

	env = utils->shell->duplicate_env;
	str = ft_split_export(s, ' ');
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