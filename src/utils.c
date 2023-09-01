/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:58:23 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/01 16:07:24 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_strjoin_free(char **str, char *add)
{
	char	*res;

	res = ft_strjoin(add, *str);
	free(*str);
	*str = res;
}
