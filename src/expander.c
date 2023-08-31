/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:20:34 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/31 19:36:16 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	expander(t_vars **tmp)
{
	while(tmp)
	{
		if (tmp->type == WORD && temp->tokens && tmp->tokens[0] == '$'
		&& tmp->tokens[1])
		change_word(&tmp);
		if (tmp->type == )
	}
	
}