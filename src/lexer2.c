/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:55 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/31 17:26:40 by kilchenk         ###   ########.fr       */
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
