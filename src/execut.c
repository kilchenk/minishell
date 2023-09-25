/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:03:14 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/21 15:56:42 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

char	*get_path(char ***paths, char **one_path, char **command_path, char *cmd)
{
	int	i;

	i = -1;
	while ((*paths)[++i])
	{
		*one_path = ft_strjoin((*paths)[i], "/");
		*command_path = ft_strjoin(*one_path, cmd);
		free(*one_path);
		if (!access(*command_path, F_OK))
		{
			ft_free(*paths);
			return (*command_path);
		}
		free(*command_path);
	}
	ft_free(*paths);
	return (NULL);
}


int	nonbuiltin_cmd(t_pipes *data, t_pipes *prev, int in_fd, int out_fd)
{
	char	*pat;

	if (data->output != -1)
		out_fd = data->output;
	else if (g_shell->last == data->pipe_i)
		out_fd = STDOUT_FILENO;
	if (data->input != -1)
		in_fd = data->input;
	else if (prev && prev->output != -1)
		in_fd = STDIN_FILENO;
	pat = get_path(data->cmd, g_shell->env);
	if (!pat)
	{
		quote_error("Error: command not found\n");
		return(STDIN_FILENO);
	}
	free(pat);
	return (need func for forc and execute)
}

int	parent_builtin(t_pipes	*pipes)
{
	int errors;

	if (ft_strncmp(pipes->argv[0], "cd", 2) == 0)
		errors = own_cd(pipes->argv[1]);
	else if (ft_strncmp(pipes->argv[0], "exit", 4) == 0)
		errors = own_exit(pipes->argv);
	// else if (ft_strncmp(pipes->argv[0], "unset", 5) == 0)
	// // errors = unset func;
	// else if (ft_strncmp(pipes->argv[0], "export", 6) == 0)
	// // errors = export func;
	else
		return (-1);
	g_shell->error = errors;
	return (0);
}

int executor(t_pipes *data)
{
	t_pipes	*prev;
	int		pipe_fd;

	pipe_fd = STDIN_FILENO;
	prev = NULL;
	while (data)
	{
		if (g_shell->last == 0 && parent_builtin(data) != -1)
		{
			data = data->next;
			continue ;
		}
		pipe_fd = nonbuiltin_cmd(data, prev, pipe_fd, -1); //here we need function for setting up the execution of external (non-built-in) commands, for our pipe_fd;
		prev = data->next;
		data = data->next;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
