/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:04:13 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/30 15:55:18 by hsievier         ###   ########.fr       */
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
			tmp->type = APPEND;	
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

