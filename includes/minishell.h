/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:51:52 by surpetro          #+#    #+#             */
/*   Updated: 2024/09/23 17:38:51 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

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


typedef struct s_shell
{
	char			*input;
	char			**str;
	t_duplicate_env	*duplicate_env;
} t_shell;

/* ------------------------ functions ------------------------ */
void	pwd(t_shell *shell);
void	ft_execve(t_shell *shell, char **env);
void	ctrl_d(t_shell *utils);
int		dollar(t_shell *shell, char **env);
void	cd(t_shell *shell);
void	echo(t_shell *shell);

/* ------------------------ utils ------------------------ */
int		ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strstr(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
