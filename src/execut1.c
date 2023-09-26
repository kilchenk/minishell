/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:36:58 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/26 17:47:51 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	fork_exec(t_pipes *data, int in_fd, int out_fd)
{
	int	pipe_fd[2];
	int	pid;

	pipe(pipe_fd);
	signals();
	pid = fork();
	if (pid == 0)
		//child proccces
	waitpid(pid, &(g_shell->error), 0);
	signals();
	//errors staff
}
