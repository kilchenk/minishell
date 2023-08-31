/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:15:59 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/30 16:18:50 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_tokens(t_vars **var)
{
	t_vars	*tmp;
	
	tmp = *var;
	while(tmp != NULL)
	{
		if (check_type(&tmp))
			continue;
		if (tmp->tokens[0] == '|' && !(tmp->tokens[1]))
			tmp->type = PIPE;
		else if (tmp->tokens[0] == '<' && tmp->tokens[1]
			&& tmp->tokens[1] == '<' && !(tmp->tokens[2]))
			tmp->type = HEREDOC;
		else if (tmp->tokens[0] == '>' && tmp->tokens[1]
			&& tmp->tokens[1] == '>' && (tmp->tokens[2]))
			tmp->type =	APPEND;	
		else if (tmp->tokens[0] == '<' && !(tmp->tokens[1]))
			tmp->type = LESS_THAN;
		else if (tmp->tokens[0] == '>' && !(tmp->tokens[1]))
			tmp->type = GREATER_THAN;
		else if (tmp->tokens[0] != ' ')
			tmp->type = WORD;
		else
			tmp->type = SPACE;
		tmp = tmp->next;
	}
}

int	check_type(t_vars **tmp)
{
	if ((*tmp)->type != -1)
	{
		*tmp = (*tmp)->next;
		return(1);
	}
	return (0);
}

