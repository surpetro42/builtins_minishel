/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headershell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:49:03 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/18 19:18:57 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_MINISHELL_H
# define BUILTINS_MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>

# define STRING 0
# define PIPE 1 // |
# define OUTPUT_REDIRECTION 2 // >
# define INPUT_REDIRECTION 3 // <
# define APPEND_OUTPUT_REDIRECTION 4 // >>
# define HERE_DOCUMENT 5 // <<


typedef struct s_duplicate_env
{
	char					*key;
	char					*vlue;
	struct s_duplicate_env	*next;
} t_duplicate_env;

#endif
