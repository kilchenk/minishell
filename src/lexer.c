/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:15:59 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/31 14:26:25 by hsievier         ###   ########.fr       */
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

void	get_word(t_vars **var)
{
	t_vars *tmp;
	
	tmp = *var;
	while(tmp)
	{
		if (tmp->type == WORD)
		{
			find_token(&tmp);
		}
		tmp = tmp->type;
	}
}

t_vars	*creat_token(int *i, char *tokens)
{
	t_vars	*new;
	
	new = malloc(sizeof(t_vars));
	new->tokens = NULL;
	if (tokens[*i] == '|')
		new->type = PIPE;
	else if (tokens[*i] == '<' && tokens[(*i) + 1] == '<' && !(tokens[(*i) + 1]))
	{
		new->type = HEREDOC;
		(*i) += 2;
		return (new);
	}
	else if (tokens[(*i)] == '>' && tokens[(*i) + 1] == '>' && !(tokens[(*i) + 1]))
	{
		new->type = APPEND;
		(*i) += 2;
		return (new);
	}
	else if (tokens[(*i)] == '<')
		new->type = LESS_THAN;
	else if (tokens[(*i)] == '>')
		new->type = GREATER_THAN;
	(*i)++;
	return (new);
}

void	find_token_algo(t_vars **tmp, t_vars **new, t_vars **new_token)
{
	int	i;

	i = 0;
	if ((*tmp)->tokens[i] == '<' || (*tmp)->tokens[i] == '>' || (*tmp)->tokens[i] == '|')
	{
		(*new)->next = creat_token(&i, (*tmp)->tokens);
		
		
	}
		
}

void	find_token(t_vars **tmp)
{
	t_vars	*new;
	t_vars	*new_token;

	new = malloc(sizeof(t_vars));
	new->tokens = NULL;
	new->type = WORD;
	find_token_algo(tmp, &new, new_token);
	free((*tmp)->tokens);
	(*tmp)->tokens = NULL;
	new->next = (*tmp)->next;
	(*tmp) = new->next;
}