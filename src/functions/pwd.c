/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:58:24 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/26 03:52:16 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_shell *shell)
{
	char	cwd[PASS_MAX];

	if (ft_strcmp(shell->input, "pwd") == 0)
	{
		if (getcwd(cwd, PASS_MAX) != NULL)
		{
			printf("%s\n", cwd);
		}
	}
}
