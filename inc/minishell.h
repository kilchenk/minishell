/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:01:13 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/30 15:17:21 by hsievier         ###   ########.fr       */
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
	t_vars		*head;
} t_shell;

#endif