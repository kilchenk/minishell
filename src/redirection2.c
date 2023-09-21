/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:57:04 by hsievier          #+#    #+#             */
/*   Updated: 2023/09/21 14:34:32 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	open_app(t_pipes **tmp, t_vars **token_tmp, int type)
{
	if (type == APPEND)
		(*tmp)->output = open((*token_tmp)->tokens, 
				O_WRONLY, O_APPEND, O_CREAT, 0777);
	else
		(*tmp)->output = open((*token_tmp)->tokens,
				O_WRONLY, O_TRUNC, O_CREAT, 0777);
	if ((*tmp)->output < 0)
		return (1);
	return (0);
}

int	quote(t_pipes **tmp, t_vars **token, int *first, int *words_count)
{
	if (!((*token)->tokens))
	{
		*token = (*token)->next;
		return (1);
	}
	(*tmp)->argv[*words_count] = ft_strdup((*token)->tokens);
	if (!(*first))
	{
		//printf("%i\n", *first);
		(*tmp)->cmd = (*tmp)->argv[*words_count];
		*first = 1;
		//printf("%i\n", *first);
	}
	// else
	// *first = 0;
	(*words_count)++;
	*token = (*token)->next;
	return (0);
}

int	pipes(t_pipes **tmp, t_vars **token_tmp, int *first, int *count_words)
{
	if (!(*first))
		return (1);
	(*tmp)->argv[*count_words] = NULL;
	*count_words = 0;
	*first = (*tmp)->pipe_i;
	*token_tmp = (*token_tmp)->next;
	(*tmp)->next = init_pipe(*first + 1);
	*tmp = (*tmp)->next;
	*first = 0;
	return (0);
}
