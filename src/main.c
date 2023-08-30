/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:17:06 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/30 14:59:26 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	word_count(char *str)
{
	int	word;

	word = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	while (*str != "\0")
	{
		word++;
		if ()
		{
			
		}
		
	}
	
	
}

char	**split_mini(char *str)
{
	char	**arr;
	int		word;

	word = word_count(str);
	arr = malloc()
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
