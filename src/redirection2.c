/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:57:04 by hsievier          #+#    #+#             */
/*   Updated: 2023/09/05 13:58:37 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	open_app(t_pipes **tmp, t_vars **token_tmp, int type)
{
	if (type == APPEND)
		(*tmp)->output = open((*token_tmp)->tokens, 
				O_WRONLY, O_APPEND, O_CREAT, 0644);
	else
		(*tmp)->output = open((*token_tmp)->tokens,
				O_WRONLY, O_TRUNC, O_CREAT, 0644);
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
		(*tmp)->cmd = (*tmp)->argv[*words_count];
		*first = 1;
	}
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