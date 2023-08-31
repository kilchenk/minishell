/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:11:00 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/31 14:39:05 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main_split(char **splitt, char *readd)
{
	add_history(readd);
	

}

char	copy_word(char *str)
{
	int		i;
	int 	wi;
	int 	len;
	char	*word;

	i = 0;
	wi = 0;
	while (str[wi] != '\0' && str[wi] != ' ' && str[wi] != '\t'
		&& str[wi] != '\n' && str[wi] != '\"' && str[wi] != '\'')
		wi++;
	len = wi;
	word = malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (*word);
}
