/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:32:31 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/05 12:36:40 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	own_pwd(void)
{
	int		i;
	char	*pwd;

	i = find_path_env(g_shell->env, "PWD");
	pwd = ft_strchr(g_shell->env[i], '=');
	pwd++;
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
