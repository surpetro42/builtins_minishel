/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:03:36 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/23 17:38:36 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	

	if (argc > 1)
		return 1;
	t_shell	*shell;
	int i;

	shell = malloc(sizeof(t_shell));
	shell->duplicate_env = NULL;
	i = 0;
	while (1)
	{
		shell->input = readline("\033[38;5;43mminishell: \033[0;000m");
		add_history(shell->input);
		ctrl_d(shell);
		pwd(shell);
		echo(shell);
		dollar(shell, env);
		cd(shell);
		// ft_execve(shell, env);
	}
	return 0;
}
