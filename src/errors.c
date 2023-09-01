/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:26:42 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/01 15:48:34 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	quote_error(char *s)
{
	ft_putstr_fd(s, 2);
	free_tokens(&(g_shell->var));
	return (1);
}

void	free_tokens(t_vars **token)
{
	t_vars	*tmp;
	t_vars	*next;

	if (!(*token))
		return ;
	tmp = *token;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->tokens);
		free(tmp);
		tmp = next;
	}
	*token = NULL;
}
