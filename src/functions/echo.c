/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:10 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/25 21:39:02 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void echo(t_shell *shell, char **env)
{
	(void)env;
	int i = 0;
	int buff = 0;
	int buff1 = 0;

	if(ft_strstr(shell->input, "echo") != NULL)
	{
		while(shell->input[i] > 32)
			i++;
		if(shell->input[i] == 32)
			i++;
		if(shell->input[i] == '$')
		{
			dollar(shell, env);
			if(shell->input[i] == '$')
				while (shell->input[i] > 32)
					i++;
		}
		if(shell->input[i] == '-' && shell->input[i + 1] == 'n')
		{
			buff = i;
			i++;
			buff1 = i;
			while (shell->input[buff1] == 'n')
				buff1++;
			if (shell->input[buff1] == ' ')
			{
				i = buff1;
				while (shell->input[i] > 32)
					i++;
				if(shell->input[i] == ' ')
						i++;
				while (shell->input[i])
				{
					write(1, &shell->input[i], 1);
					i++;
				}
			}
			else
			{
				i = buff;
				if(shell->input[i] == ' ')
						i++;
				while (shell->input[i])
				{
					write(1, &shell->input[i], 1);
					i++;
				}
				write(1, "\n", 1);
			}
		}
		else
		{
			if(shell->input[i] == ' ')
					i++;
			while (shell->input[i])
			{
				write(1, &shell->input[i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
	}
}
