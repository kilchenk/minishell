/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:13:24 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/13 18:59:14 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include "../Libft/get_next_line.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define MAX_PATH 2000
# define SYNTAX_ERROR "Error: syntax error near unexpected token\n"

typedef enum e_token
{
	WORD,
	PIPE,
	SPACE,
	GREATER_THAN,
	LESS_THAN,
	HEREDOC,
	APPEND,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
}	t_type;

typedef struct s_vars
{
	int				lenght;
	char			*tokens;
	int				type;
	struct s_vars	*next;
}	t_vars;

typedef struct s_pipes
{
	char		 	**argv;
	char		 	*cmd;
	int				input;
	int				output;
	int				fd[2];
	int				pipe_i;
	char			*heredoc;
	struct s_pipes	*next;
}	t_pipes;


typedef struct s_shell
{
	char		**env;
	int			counter;
	int			error;
	int			last;
	t_pipes		*pipes;
	t_vars		*var;
}	t_shell;

extern t_shell *g_shell;

//lexer
void	lexer(void);
void	get_tokens(t_vars **var);
void	find_token(t_vars **tmp);
void	get_word(t_vars **var);
void	join_and_free(char **str, char plus);
void	token_algo(t_vars *tmp, t_vars **new, t_vars **new_token);
t_vars	*create_token(int *i, char *tokens);
int		check(t_vars **tmp);
void	free_tokens(t_vars **tok);

//addfunct
int		check(t_vars **tmp);
int		quote_error(char *s);
int		open_app(t_pipes **tmp, t_vars **token_tmp, int type);
void	ft_strjoin_free(char **str, char *add);
int		main_split(char **splitt, char *readd);
char	*copy_word(char *str);
int		word_count(char *str);
void	place_word(char **arr, char *str);
char	**split_mini(char *str);
char	*double_quote(char *str);
void	expander(t_vars **tmp);
t_pipes	*redirection(t_vars **token);
void	charjoin_free(char **str, char add);
int		pipes(t_pipes **tmp, t_vars **token_tmp, int *first, int *words_count);
int		quote(t_pipes **tmp, t_vars **token, int *first, int *words_count);
t_pipes	*init_pipe(int index);
int		find_path_env(char **env, char *key);
char	*cut_key(char **env, int index, char *key);
void	dollar(char **ret, char *info, int *i);
void	change_quotes(t_vars *tmp);
void	change_words(t_vars *tmp);
void	init_main(int argc, char **argv, char **envp);
int		envpp(char **envp);
int		executor(t_pipes *data);
void	init_envp(int *counter, int *i, char ***tmp, char **envp);

#endif
