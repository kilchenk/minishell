/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:55 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/01 12:02:35 by hsievier         ###   ########.fr       */
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
	find_token(&(g_shell->var));
}