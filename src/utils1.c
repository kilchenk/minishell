/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:57:06 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/02 19:08:13 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_in_dollar(char *key, char *rett)
{
	free(key);
	free(rett);
}

void	free_main(char *string, char **split)
{
	free_tokens(&(g_shell->var));
	free_pipe(&(g_shell->pipes));
	free(string);
	free(split);
}
