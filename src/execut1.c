/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:36:58 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/02 18:55:09 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	child_outfd(int out_fd, int pipe_fd[])
{
	if (out_fd == -1 || out_fd == -2)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		return (pipe_fd[1]);
	}
	if (out_fd != STDOUT_FILENO)
		dup2(out_fd, STDOUT_FILENO);
	return (out_fd);
}

void	child_process(t_pipes *data, int in_fd, int out_fd, int pipe_fd[])
{
	int		out;
	char	*ppath;

	if (in_fd != STDIN_FILENO)
		dup2(in_fd, STDIN_FILENO);
	out = child_outfd(out_fd, pipe_fd);
	if (parent_builtin(data) != -1)
		exit(0);
	ppath = get_path(data->cmd, g_shell->env);
	execve(ppath, data->argv, g_shell->env);
	quote_error("Error: couldn't run process\n");
	close(in_fd);
	close(out);
	exit(-1);
}

int	fork_exec(t_pipes *data, int in_fd, int out_fd)
{
	int	pipe_fd[2];
	int	pid;

	pipe(pipe_fd);
	signals();
	pid = fork();
	if (pid == 0)
		child_process(data, in_fd, out_fd, pipe_fd);
	waitpid(pid, &(g_shell->error), 0);
	signals();
	if ((g_shell->error) > 255)
		(g_shell->error) /= 256;
	close(pipe_fd[1]);
	if (in_fd > 2)
		close(in_fd);
	if (out_fd > 2)
		close(out_fd);
	return (pipe_fd[0]);
}
