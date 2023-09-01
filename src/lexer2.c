/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:55 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/01 12:33:04 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	*join_and_free(char **str, char plus)
{
	char	second[2];
	char	*result;

	second[0] = plus;
	second[1] = '/0';
	result = ft_strjoin(str, second);
	return (result);
}

void	lexer(void)
{
	get_tokens(&(g_shell->var));
	get_word(&(g_shell->var));
}

void	get_word(t_vars **var)
{
	t_vars	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (tmp->type == WORD)
		{
			find_token(&var);
		}
		tmp = tmp->next;
	}
}
