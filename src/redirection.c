/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:15:44 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/01 19:56:02 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_pipes	*init_pipe(int index)
{
	t_pipes	*pipe;
	int		i;
	
	i = 0;
	pipe = malloc (sizeof(t_pipes));
	pipe->argv = malloc(sizeof(char *) * 50);
	while (i < 50)
	{
		pipe->argv[i] = NULL;
		i++;
	}
	pipe->cmd = NULL;
	pipe->heredoc = NULL;
	pipe->input = -1;
	pipe->output = -1;
	pipe->next = NULL;
	pipe->pipe_i = index;
	return (pipe);
	
}

t_pipes	*redirection(t_vars **token)
{
	t_vars	*token_tmp;
	t_pipes	*tmp;
	int		tfrist;
	int		count_words;

	g_shell->pipes = init_pipe(0);
	tmp = g_shell->pipes;
	tfrist = 0;
	count_words = 0;
	token_tmp = 0;
	//we need loop(loop this function iterates through a linked list of tokens and handles various token types.)
	return ((g_shell->pipes));
}
