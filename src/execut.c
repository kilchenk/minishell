/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:03:14 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/20 13:24:03 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		//here we need function for setting up the execution of external (non-built-in) commands, for our pipe_fd;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
