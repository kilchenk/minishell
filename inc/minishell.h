/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:13:24 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/31 11:58:16 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

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

typedef enum e_token
{
	WORD,
	PIPE,
	SPACE,
	GREATER_THAN,
	LESS_THAN,
	HEREDOC,
	APPEND
}	t_type;

typedef struct s_vars
{
	int				lenght;
	char			*tokens;
	int				type;
	struct s_vars	*next;
} t_vars;

typedef struct s_shell
{
	char		**env;
	t_vars		*var;
} 	t_shell;

extern t_shell	*v;
//lexer
void	get_tokens(t_vars **var);

//addfunct
int		check_type(t_vars **tmp);
int		word_count(char *str);
int		place_word(char **arr, char *str);
int		place_word(char **arr, char *str);
char	**split_mini(char *str);
char	 *double_quote(char *str);

#endif