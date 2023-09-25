/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:03:14 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/21 15:56:42 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	unset(char **ar)
{
	int	i;
	int	j;

	i = 0;
	while (ar[i])
	{
		j = find_path_env(g_shell->env, ar[i]);
		if (j != -1 && g_shell->env[j])
		{
			free((g_shell->env[j]));
			g_shell->env[j] = NULL;
		}
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(ar[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
