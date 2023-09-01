/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:11:00 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/31 20:18:07 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void init_token(t_vars **tmp,  t_vars **token, char **split, int *word)
{
	*tmp = malloc(sizeof(t_vars));
	(*tmp)->tokens = ft_strdup(split[*word]);
	(*tmp)->lenght = ft_strlen(split[*word]);
	(*tmp)->type = -1;
	(*tmp)->next = *token;
	*token = *tmp;
	(*word)--;
}

void	cat_quote(int *word, char **split, t_type **token)
{
	char	*quote;
	t_vars	*tmp;

	tmp = malloc(sizeof(t_type));
	tmp->tokens = NULL;
	quote = split[*word][0];
	(*word)--;
	while (*word >= 0 && split[*word][0] != quote)
	{
		ft_strjoin_free(&(tmp->tokens), split[*word]);
		(*word)--;
	}
	tmp->lenght = ft_strlen(tmp->tokens);
	if (quote == '\'')
		tmp->type = SINGLE_QUOTES;
	else
		tmp->type = DOUBLE_QUOTES;
	tmp->next = *token;
	*token = tmp;
	(*word)--;
}

int	close_quote(char **split)
{
	int	i;
	int	quote;

	while (split[i])
	{
		if (quote)
		{
			if (quote == 1 && (ft_strncmp(split[i], '\'', 1)))
				quote = 0;
			else if (quote == 2 && (ft_strncmp(split[i], '\"', 1)))
				quote = 0;
		}
		else if ((ft_strncmp(split[i], '\'', 1) == 0))
			quote = 1;
		else if ((ft_strncmp(split[i], '\"', 1) == 0))
			quote = 2;
		i++;
	}
	if (quote)
		return (1);
	return (0);
}

int	init_list(t_shell **token, char *read, char **split)
{
	int		word;
	t_type	*tmp;

	if (close_quote(split) == 1)
	{
		quote_error("Error: quote not closed\n");
		return (1);
	}
	word = word_count(read);
	word -= 1;
	while (word >= 0)
	{
		if(split[word][0] == '\'' || split[word][0] == '\"')
		{
			cat_quote(&word, split, token);
			continue ;
		}
		init_token(&tmp, token, split, &word);
	}
	return (0);
}

int	main_split(char **splitt, char *readd)
{
	add_history(readd);
	if (init_list(&(g_shell->token), readd, splitt) == 1)
	{
		free(readd);
		free(splitt);
		return (1);
	}
	//here we need ft lexer(start)!!!!
	//after resirection
	//free all
}

char	copy_word(char *str)
{
	int		i;
	int		wi;
	int		len;
	char	*word;

	i = 0;
	wi = 0;
	while (str[wi] != '\0' && str[wi] != ' ' && str[wi] != '\t'
		&& str[wi] != '\n' && str[wi] != '\"' && str[wi] != '\'')
		wi++;
	len = wi;
	word = malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (*word);
}
