/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:17:06 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/31 11:58:30 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	lexer(void)
{
	get_tokens(&(v->var));
	
}

int	main(int argc, char **argv, char **envp)
{
	char	*string;
	char	**split;

	(void)argc;
	(void)argv;
	while (1)
	{
		string = readline("minishel > ");
		if (!string)
			return (0);
		if (!(ft_strncmp(string, "\0", 1)))
		{
			free(string);
			continue ;
		}
		split = split_mini(string);
	}
}
