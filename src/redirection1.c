/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:57:04 by hsievier          #+#    #+#             */
/*   Updated: 2023/09/04 13:05:51 by hsievier         ###   ########.fr       */
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