/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:52:36 by surpetro          #+#    #+#             */
/*   Updated: 2024/10/07 19:01:40 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ctrl_d(char *str, utils_t *utils)
{
	if (str == NULL)
	{
		free(utils);
		exit(write(1, "exit\n", 5));
	}
}
