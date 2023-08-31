/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:17:06 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/30 19:06:01 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
