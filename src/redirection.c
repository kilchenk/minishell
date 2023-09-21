/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:15:44 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/21 15:46:26 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void charjoin_free(char **str, char add)
{
	char	*res;
	char	*adder;

	adder = malloc(2);
	adder[0] = add;
	adder[1] = 0;
	res = ft_strjoin(*str, adder);
	free(*str);
	free(adder);
	*str = res;
}

char	*here_doc_init(char	**file_name, t_vars	**token_tmp, t_pipes **tmp, int	*file)
{
	char	*limiter;
	*file_name = ft_strdup(".here_doc");
	charjoin_free(file_name, (*tmp)->pipe_i + '0');
	limiter = (*token_tmp)->tokens;
	*file = open(*file_name, O_CREAT, O_WRONLY, O_TRUNC, 0777);
	return (limiter);
}

int here_doc(t_vars **token_tmp, t_pipes **tmp)
{
	int		input;
	char	*buf;
	char	*limiter;
	char	*file_name;
	
	limiter = here_doc_init(&file_name, token_tmp, tmp, &input);
	if (input < 0)
		return (quote_error("Error: coldn't open \"heredoc\""));
	while (1)
	{
		buf = readline("> ");
		charjoin_free(&buf, '\n');
		if (!buf)
		{
			free(buf);
			return (1);
		}
		if (!ft_strncmp(limiter, buf, ft_strlen(buf) - 1))
			break ;
		write(input, buf, ft_strlen(buf));
		free(buf);
	}
	close(input);
	free(buf);
	(*tmp)->input = open(file_name, O_RDONLY);
	(*tmp)->heredoc = file_name;
	*token_tmp = (*token_tmp)->next;
	return (0);
}

int	red_create(t_vars	**token_tmp, t_pipes	**tmp)
{
	int	type;
	type = (*token_tmp)->type;
	*token_tmp = (*token_tmp)->next;
	while ((*token_tmp) && ((*token_tmp)->type == SPACE 
			|| ((*token_tmp)->type == WORD && !((*token_tmp)->tokens))))
		*token_tmp = (*token_tmp)->next;
	if (!(*token_tmp) || ((*token_tmp)->type != SINGLE_QUOTES
			&& (*token_tmp)->type != DOUBLE_QUOTES
			&& (*token_tmp)->type != WORD))
		return (quote_error(SYNTAX_ERROR));
	if (type == HEREDOC)
		return (here_doc(token_tmp, tmp));
	if (type == LESS_THAN)
	{
		(*tmp)->input = open((*token_tmp)->tokens, O_RDONLY);
		if ((*tmp)->input < 0)
			return (quote_error("Error"));
	}
	else if (type == GREATER_THAN || type == APPEND)
	{
		if (open_app(tmp, token_tmp, type))
			return (quote_error("Error"));
	}
	*token_tmp = (*token_tmp)->next;
	return (0);
}

int red_loop(t_pipes **tmp, t_vars **token, int *first, int *words_count)
{
	while (*token)
	{
		if ((*token)->type == APPEND || (*token)->type == HEREDOC
			|| (*token)->type == LESS_THAN || (*token)->type == GREATER_THAN)
		{
			// printf("1\n");
			red_create(token, tmp);
			if ((g_shell->pipes) == NULL)
				return (1);
		}
		else if ((*token)->type == SINGLE_QUOTES
			|| (*token)->type == DOUBLE_QUOTES || (*token)->type == WORD)
		{
			// printf("2\n");
			if (quote(tmp, token, first, words_count))
				continue ;
		}
		else if ((*token)->type == PIPE)
		{
			// printf("3\n");
			if (pipes(tmp, token, first, words_count))
				return (quote_error("Error"));
		}
		else
		{
			// printf("4\n");
			*token = (*token)->next;
		}
	}
	return (0);
}

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

t_pipes	*redirection(t_vars **tokens)
{
	t_vars	*token_tmp;
	t_pipes	*tmp;
	int		tfrist;
	int		count_words;

	g_shell->pipes = init_pipe(0);
	tmp = g_shell->pipes;
	token_tmp = *tokens;
	tfrist = 0;
	count_words = 0;
	if (red_loop(&tmp, &token_tmp, &tfrist, &count_words))
		return (NULL);
	if (!tfrist)
	{
		printf("%i\n", tfrist);
		quote_error("Error: syntax error\n");
		return (NULL);
	}
	tmp->argv[count_words] = NULL;
	return ((g_shell->pipes));
}
