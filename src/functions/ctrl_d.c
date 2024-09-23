/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:52:36 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/23 21:11:17 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ctrl_d(t_shell *utils)
{
	if(utils->input == NULL)
	{
		free(utils);
		exit(write(1, "exit\n", 5));
	}
}
